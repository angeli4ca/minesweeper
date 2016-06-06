/**
  @brief implementation of Cell class that that represents one cell on the board
  @author Angelica Patsko
  @date 4/28/2016
*/

#include "cell.h"
#include <QPainter>
#include <QMouseEvent>
/**
 * @brief  constructor
 * @param i - row-coordinate
 * @param j - column-coordinate
 * @param parent - passed for memory management purposes
 */
Cell::Cell(int i, int j, QWidget *parent): QPushButton(parent), m_i(i), m_j(j), m_value(0), m_isMine(false), m_isOpen(false), m_isFlag(false) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFixedSize(30, 30);
}

/**
 * @brief Cell::i - getter of i
 * @return the row-coordinate
 */
int Cell::i() { return m_i; }

/**
 * @brief Cell::j - getter of j
 * @return the column-coordinate
 */
int Cell::j() { return m_j; }

/**
 * @brief Cell::value getter of m_value
 * @return m_value - number of mines around
 */
int Cell::value() { return m_value; }

/**
 * @brief Cell::incValue increments the number of mines around the square
 */
void Cell::incValue() { ++m_value; }

/**
 * @brief Cell::isMine checks whether the square is mined
 * @return true if it is
 */
bool Cell::isMine() { return m_isMine; }

/**
 * @brief Cell::setMine sets the Mine on the square
 */
void Cell::setMine() { m_isMine = true; repaint(); }

/**
 * @brief Cell::isOpen checks whethe the square is opened
 * @return true if it is
 */
bool Cell::isOpened() { return m_isOpen; }

/**
 * @brief Cell::setOpen sets the m_isOpen property
 */
void Cell::setOpen() { m_isOpen = true; repaint(); }

/**
 * @brief Cell::swapFlag sets/removes the flag on the square
 */
void Cell::swapFlag() { m_isFlag = !m_isFlag; repaint(); }

/**
 * @brief Cell::paintEvent - paints circles on the cells, red for mine, blue for flag
 * @param event - paint event
 */
void Cell::paintEvent(QPaintEvent *event) {
    if (isOpened() && isMine() == false && 0 == m_value)
        return;
    QPushButton::paintEvent(event);
    QPainter p(this);
    if (isOpened()) {
        if (isMine()) {
            p.setBrush(QBrush(Qt::red, Qt::SolidPattern));
            p.drawEllipse(2, 2, width() - 4, height() - 4);
            return;
        }
        setText(QString::number(m_value));
        return;
    }
    if (m_isFlag) {
    p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    p.drawEllipse(2, 2, width() - 4, height() - 4);
  }
}

/**
** * @brief Cell::mouseReleaseEvent processes left- and right- mouse clicks
** * @param e - mouse event
** */
void Cell::mouseReleaseEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton) emit clicked_left();
    if (e->button() == Qt::RightButton) emit clicked_right();
}
