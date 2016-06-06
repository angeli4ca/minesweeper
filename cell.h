/**
  @brief declaration of Сell class that represents one cell on the board
  @author Angelica Patsko
  @date 4/28/2016
*/

#ifndef DOT_H
#define DOT_H
#include <QPushButton>

/**
 * @brief The Cell class represents one Cell on the board
 */
class Cell : public QPushButton {
  Q_OBJECT

public:
    Cell(int i, int j, QWidget *parent = 0);
    int i();
    int j();
    bool isMine();
    void setMine();
    void incValue();
    int value();
    void setOpen();
    bool isOpened();
    void swapFlag();

signals:
    void clicked_left();
    void clicked_right();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    //row- and column- coordinates
    int m_i, m_j;
    //value containing in a square = number of mines around
    int m_value;
    //checks whether the square is mined
    bool m_isMine;
    bool m_isOpen;
    bool m_isFlag;
};

#endif // DOT_H
