/**
  @brief declaration of MinesweeperBoard class that works with interface
  @author Angelica Patsko
  @date 4/22/2016
*/



#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QMenuBar>
#include <QMainWindow>
#include <QMessageBox>
#include "clock.h"
#include "cell.h"
#include "board.h"



namespace Ui{
class MinesweeperBoard;
}

class Minesweeper : public QWidget
{
    Q_OBJECT

public:
    explicit Minesweeper(QWidget *parent = 0, size_t boardSize = 8, size_t minesNumber = 10);
    ~Minesweeper();

public slots:
   void info();
   void about();

signals:
   void game_over();
   void easy_game_begin();
   void medium_game_begin();
   void hard_game_begin();

private:
    Ui::MinesweeperBoard *ui;

    //parameters we need to create a new game depending on the level
    size_t boardSize;
    size_t minesNumber;

    //layouts
    QVBoxLayout* v_layout;
    QHBoxLayout* h_layout;

    //topmenu items
    QMenuBar* menubar;
    QMenu* gameMenu;
    QMenu* helpMenu;

    //the top part
    QWidget* top;
    QLabel* labelBombs;
    QLabel* labelTime;
    QPushButton* startOverButton;

    //the actual gameboard
    QWidget* board;
    QPushButton** cells;

    Board* m_field;
    Clock* m_clock;
};

#endif // MINESWEEPERBOARD_H





