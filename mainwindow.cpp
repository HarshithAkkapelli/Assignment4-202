#include <bits/stdc++.h>
using namespace std;
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameEngine.h"
#include <time.h>
#include "Player.h"
#include "InputStrategy.h"
#include "RandomStrategy.h"
#include "SmartStrategy.h"
#include <sstream>
#include "GameEngine.h"
#include <time.h>
#include "Player.h"
#include "InputStrategy.h"
#include "RandomStrategy.h"
#include "SmartStrategy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rock->setEnabled(false);
    ui->paper->setEnabled(false);
    ui->scissors->setEnabled(false);
    ui->nextRound->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_startGameButton_clicked()
{
    string strategy_ = ui->choice->currentText().toStdString();
    if(strategy_ == "RANDOM"){
        strategy = "r";
    }
    else{
        strategy = "s";
    }
    numRounds = ui->rounds->currentText().toInt();
    ui->choice->setEnabled(false);
    ui->rounds->setEnabled(false);
    ui->startGameButton->setEnabled(false);
    ui->rock->setEnabled(true);
    ui->paper->setEnabled(true);
    ui->scissors->setEnabled(true);
    ui->nextRound->setEnabled(true);
    ui->computerWins->clear();
    ui->humanWins->clear();
    ui->ties->clear();

    ui->computerChoice->clear();
    ui->humanChoice->clear();
    ui->winner->clear();
    ui->predHuman->clear();

    ui->paper->setAutoExclusive(false);
    ui->rock->setAutoExclusive(false);
    ui->scissors->setAutoExclusive(false);

    ui->paper->setChecked(false);
    ui->rock->setChecked(false);
    ui->scissors->setChecked(false);

    ui->paper->setAutoExclusive(true);
    ui->rock->setAutoExclusive(true);
    ui->scissors->setAutoExclusive(true);

    round = 1;
}


void MainWindow::on_rock_clicked()
{
    ui->humanChoice->setText("ROCK");
    gamePlay("R");
}

void MainWindow::gamePlay(string humanChoice) {
    srand(time(0));
    /*
    auto stra = new InputStrategy(humanChoice);
    Player humanPlayer("Human", stra);
*/

    GameStrategy * computerGameStrategy = nullptr;
    if (strategy == "s") {
        //std::cout <<  "Smart Strategy is chosen for Computer player" << std::endl;
        computerGameStrategy = new SmartStrategy(static_cast<size_t>(5));
    } else {
        //std::cout <<  "Random Strategy is chosen for Computer player" << std::endl;
        computerGameStrategy = new RandomStrategy();
    }
    //std::cout << std::endl;

    Player computerPlayer("Computer", computerGameStrategy);



/*
 *     GameEngine gameEngine;
    auto round_ = gameEngine.roundplay(round, humanPlayer, computerPlayer);
    std::string winn = gameEngine.roundlog(humanPlayer, computerPlayer, round_);
    PlayerStats humanStats = humanPlayer.getPlayerStats();
    PlayerStats computerStats = computerPlayer.getPlayerStats();

    ui->computerChoice->setText(QString::fromStdString(getGameChoice(round_.choice2)));
    ui->winner->setText(QString::fromStdString(winn));
    ui->humanWins->setText(QString::number(humanStats.getWins()));
    ui->computerWins->setText(QString::number(computerStats.getWins()));
    ui->ties->setText(QString::number(computerStats.getTies()));
    round++;
 * */
}
