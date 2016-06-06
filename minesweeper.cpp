/**
  @brief implementation of MinesweeperBoard class that directly works with the game logic and interface
  @author Angelica Patsko
  @date 4/22/2016
*/

#include "minesweeper.h"
#include "mainwindow.h"
#include "ui_minesweeperboard.h"

/**
 * @brief MinesweeperBoard::MinesweeperBoard
 * @param parent type QWidget, helps with the memory management
 * @param boardSz size of the gameboard created
 * @param minesNum number of bombs on the gameboard
 */
Minesweeper::Minesweeper(QWidget *parent, size_t boardSz, size_t minesNum) :
    QWidget(parent), ui(new Ui::MinesweeperBoard), boardSize(boardSz), minesNumber(minesNum)
{
    ui->setupUi(this);

    //resizing the window
    switch (boardSz){
    case 8:
        parent->setFixedSize(425,370);
        break;
    case 16:
        parent->setFixedSize(490,570);
        break;
    case 20:

        parent->setFixedSize(620,670);
        break;
    default: break;
    }

    //creating and organizing menubar with two menus Game and Help
    menubar  = new QMenuBar(this);

    gameMenu = menubar->addMenu("Game");

    QAction* newAct = new QAction("New",this);
    gameMenu->addAction(newAct);
    QObject::connect(newAct, SIGNAL(triggered()), parent, SLOT(game_over()));

    QAction* beginnerAct = new QAction("Beginner",this);
    gameMenu->addAction(beginnerAct);
    QObject::connect(beginnerAct, SIGNAL(triggered()), parent, SLOT(easy_game_begin()));

    QAction* intermediateAct = new QAction("Intermediate",this);
    gameMenu->addAction(intermediateAct);
    QObject::connect(intermediateAct, SIGNAL(triggered()), parent, SLOT(medium_game_begin()));

    QAction* expertAct = new QAction("Expert",this);
    gameMenu->addAction(expertAct);
    QObject::connect(expertAct, SIGNAL(triggered()), parent, SLOT(hard_game_begin()));

    helpMenu = menubar->addMenu("Help");

    QAction* instrAct = new QAction("Instructions",this);
    helpMenu->addAction(instrAct);
    QObject::connect(instrAct, SIGNAL(triggered()), this, SLOT(info()));

    QAction* aboutAct = new QAction("About",this);
    helpMenu->addAction(aboutAct);
    QObject::connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    //working with the top part of the window where labels and pushbutton are
    top = new QWidget;
    labelBombs = new QLabel;
    labelBombs->setText("Bombs in the Game: " + QString::number(minesNumber));
    labelBombs->setAlignment(Qt::AlignCenter);

    startOverButton = new QPushButton;
    startOverButton->setText("Start over!");
    QObject::connect(startOverButton, SIGNAL(clicked()), parent, SLOT(game_over()));


    Clock* m_time = new Clock(this);


    //adding the label, the button, and the clock to the layout
    h_layout = new QHBoxLayout(top);
    h_layout->addWidget(labelBombs);
    h_layout->addWidget(startOverButton);
    h_layout->addWidget(m_time);

    m_field = new Board(this, boardSize, minesNumber);

    //putting everything together
    v_layout = new QVBoxLayout;
    v_layout->addWidget(top, 0, Qt::AlignCenter);
    v_layout->addWidget(m_field,0, Qt::AlignCenter);
    this->setLayout(v_layout);
}

/**
 * @brief MinesweeperBoard::~MinesweeperBoard deallocates memory for Ui::MinesweeperBoard and QPushButton**
 */
Minesweeper::~Minesweeper(){
    delete ui;
}

/**
 * @brief Minesweeper::info is the slot that shows a QMessageBox with the instructions to the game
 */
void Minesweeper::info(){
    QMessageBox::information(0, "Instructions", "The object of the game is to find the empty squares while avoiding the mines. If you uncover a mine, the game ends; if you uncover an empty square, you keep playing. Uncover a number, and it tells you how many mines lay hidden in the eight surrounding squares — the information you use to deduce which nearby squares are safe to click. To uncover a square, right-click it; to identify a potential mine, left-click the square. Good luck!");
}

/**
 * @brief Minesweeper::about is the slot that shows a QMessageBox with the the information about the author
 */
void Minesweeper::about(){
    QMessageBox::information(0,"About", "The game was created by Angelica Patsko. All rights reserved.");
}
