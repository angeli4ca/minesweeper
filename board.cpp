/**
  @brief implementation of Board class that represents the mined board and works with the main logic of the game
  @author Angelica Patsko
  @date 4/28/2016
*/

#include "board.h"
#include "cell.h"
#include <QGridLayout>
#include <QMessageBox>

/**
 * @brief Board::Board constructor, sets up the board
 * @param parent used for memory management purposes
 * @param m_n number of rows and columns on the board
 * @param m_mineNumber number of mines
 */
Board::Board(QWidget *parent, int m_n, int m_mineNumber ): QWidget(parent) {

    m_isGameActive = true;
    this->m_n = m_n;
    this->m_mineNumber = m_mineNumber;
    QGridLayout *layout = new QGridLayout(this);

    m_board = new Cell*[m_n*m_n];

    //adds cells to the board
    for (int i = 0; i < m_n; ++i) {
        for (int j = 0; j < m_n; ++j) {
        m_board[i*m_n+j] = new Cell(i, j, this);
        layout->addWidget(m_board[i*m_n+j], i, j, 1, 1);
        connect(m_board[i*m_n+j], SIGNAL(clicked_left()), this, SLOT(on_CellClickedLeft()));
        connect(m_board[i*m_n+j], SIGNAL(clicked_right()), this, SLOT(on_CellClickedRight()));
        }
    }

    //adding mines to the board
    for (int i = 0; i < m_mineNumber;) {
        int rand_i = qrand() % m_n;
        int rand_j = qrand() % m_n;
        Cell *p = m_board[rand_i*m_n+rand_j];
        if (p->isMine())
            continue;
        else {
            p->setMine();
            ++i;
        }
    }

    //setting the mines number by checking the surrounding cells
    for (int i = 0; i < m_n; ++i) {
        for (int j = 0; j < m_n; ++j) {
            if (m_board[i*m_n+j]->isMine()) {
            if (isValidCoord(i - 1, j - 1)) m_board[(i - 1)*m_n + j - 1]->incValue();
            if (isValidCoord(i - 1, j)) m_board[(i - 1)*m_n+j]->incValue();
            if (isValidCoord(i - 1, j + 1)) m_board[(i - 1)*m_n+j + 1]->incValue();
            if (isValidCoord(i, j - 1)) m_board[i* m_n + j - 1]->incValue();
            if (isValidCoord(i, j + 1)) m_board[i* m_n + j + 1]->incValue();
            if (isValidCoord(i + 1, j - 1)) m_board[(i + 1)*m_n + j - 1]->incValue();
            if (isValidCoord(i + 1, j)) m_board[(i + 1)*m_n+j]->incValue();
            if (isValidCoord(i + 1, j + 1)) m_board[(i + 1)*m_n+j + 1]->incValue();
            }
        }
    }
}



/**
 * @brief Board::isValidCoord checks whether the coordinanes fall in this range [0; m_n -1]
 * @param i row-coordinate
 * @param j column
 * @return true if the coordinates are in the allowed range
 */
bool Board::isValidCoord(int i, int j) {
    return i >= 0 && j >= 0 && i < m_n && j < m_n;
}


/**
 * @brief Board::is_win checks if a player opened all the unmined cells
 * @return true if he/she did
 */
bool Board::is_win() {
    int n = m_n * m_n - m_mineNumber;
    for (int i = 0; i < m_n; ++i)
        for (int j = 0; j < m_n; ++j)
            n -= m_board[i*m_n+j]->isOpened();
    return 0 == n;
}

/**
 * @brief Board::openCell opens the cell with (i,j) coordinates, if zero, opens suuronding o-cells as well
 * @param i row-coordinate
 * @param j column-coordinate
 */
void Board::openCell(int i, int j) {
    if (!isValidCoord(i, j)) return;
    Cell *p = m_board[i*m_n+j];
    if (p->isOpened())
        return;
    p->setOpen();
    if (p->value()) return;
    //open all other cells with 0 value
    openCell(i - 1, j);
    openCell(i + 1, j);
    openCell(i, j - 1);
    openCell(i, j + 1);
}

/**
 * @brief Board::on_CellClickedRight processes right clicks on closed cells
 */
void Board::on_CellClickedRight() {
    if (!m_isGameActive) return;
    Cell *t = reinterpret_cast<Cell*>(sender());
    if (t->isOpened()) return;
    t->swapFlag();
}

/**
 * @brief Board::openAll reveals all the cells
 */
void Board::openAll() {
    for (int i = 0; i < m_n; ++i)
        for (int j = 0; j < m_n; ++j)
            m_board[i*m_n+j]->setOpen();
}

/**
 * @brief Board::on_CellClickedLeft processes right clicks on closed cells, if click on mined cell - lose
 */
void Board::on_CellClickedLeft() {
    if (!m_isGameActive)
        return;
    Cell* t = reinterpret_cast<Cell*>(sender());
    if (t->isOpened())
        return;
    //clicking on mined cell
    if (t->isMine()) {
        m_isGameActive = false;
        QMessageBox::information(0, "Information", "Sorry, you lost");
        openAll();
        return;
    }
    openCell(t->i(), t->j());
    //if opened the last cell
    if (is_win()) {
        m_isGameActive = false;
        QMessageBox::information(0, "Information", "Congratulations! You won!");
        openAll();
    }
}

