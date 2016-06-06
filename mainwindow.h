/**
  @brief declaration of MainWindow class that handles the first window you see when you launch the program
  @author Angelica Patsko
  @date 4/22/2016
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "minesweeper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void easy_game_begin();
    void medium_game_begin();
    void hard_game_begin();
    void game_over();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Minesweeper* board;

    QMenuBar* menubar;
    QMenu* gameMenu;
    QMenu* helpMenu;
};

#endif // MAINWINDOW_H

