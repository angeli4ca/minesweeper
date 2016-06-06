/**
  @brief implementation of MainWindow class that handles the first window you see when you launch the program
  @author Angelica Patsko
  @date 4/22/2016
*/

#include "mainwindow.h"
#include "minesweeper.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow class to display the main window where you choose the difficulty level you'd like to play
 * @param parent - helps with memory management (QWidget uses RAII)
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connecting the buttons to start a game (choosing the difficulty level)
    QObject::connect(ui->pushButtonBeginner,SIGNAL(clicked()),this, SLOT(easy_game_begin()));
    QObject::connect(ui->pushButtonIntermediate,SIGNAL(clicked()),this, SLOT(medium_game_begin()));
    QObject::connect(ui->pushButtonExpert,SIGNAL(clicked()),this, SLOT(hard_game_begin()));
}

/**
 * @brief MainWindow::easy_game_begin starts a game in a beginner mode
 */

void MainWindow::easy_game_begin() {
    board = new Minesweeper(this,8,10);
    this->setCentralWidget(board);
}

/**
 * @brief MainWindow::medium_game_begin starts a game in an intermediate mode
 */

void MainWindow::medium_game_begin() {
    board = new Minesweeper(this,16,30);
    this->setCentralWidget(board);
}

/**
 * @brief MainWindow::hard_game_begin starts a game in an expert mode
 */
void MainWindow::hard_game_begin() {
    board = new Minesweeper(this,20,60);
    this->setCentralWidget(board);
}

/**
 * @brief MainWindow::game_over returns to the initial window
 */
void MainWindow::game_over() {
    QWidget* wid = this->centralWidget();
    this->setFixedSize(420,330);
    wid->setParent(nullptr);
    ui->setupUi(this);
    QObject::connect(ui->pushButtonBeginner,SIGNAL(clicked()),this, SLOT(easy_game_begin()));
    QObject::connect(ui->pushButtonIntermediate,SIGNAL(clicked()),this, SLOT(medium_game_begin()));
    QObject::connect(ui->pushButtonExpert,SIGNAL(clicked()),this, SLOT(hard_game_begin()));
}


/**
 * @brief MainWindow::~MainWindow deallocates memory for Ui::MainWindow
 */

MainWindow::~MainWindow()
{
    delete ui;
}


