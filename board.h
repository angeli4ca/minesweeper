/**
  @brief declaration of Board class that represents the mined board and works with the main logic of the game
  @author Angelica Patsko
  @date 4/28/2016
*/

#ifndef FIELD_H
#define FIELD_H
#include <QWidget>
#include "cell.h"
#include "clock.h"


/**
 * @brief The Board class represents the mined board
 */
class Board :public QWidget {

  Q_OBJECT

public:

  Board(QWidget *parent = 0, int m_n = 8, int m_mineNumber = 10);

protected:

  void openAll();
  bool isValidCoord(int i, int j);
  void openCell(int i, int j);
  bool is_win();
  int m_n;
  int m_mineNumber;
  Cell** m_board;
  Clock* m_clock;
  bool m_isGameActive;

protected slots:
  void on_CellClickedLeft();
  void on_CellClickedRight();
};

#endif // FIELD_H
