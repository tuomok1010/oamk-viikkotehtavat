#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QProgressBar>
#include <QButtonGroup>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    central_widget(new QWidget(this)),

    bar_player_1(new QProgressBar(central_widget)),
    bar_player_2(new QProgressBar(central_widget)),

    btn_group_timers(new QButtonGroup(central_widget)),

    btn_switch_1(new QPushButton(QApplication::translate("btn_switch_1", "switch player"), central_widget)),
    btn_switch_2(new QPushButton(QApplication::translate("btn_switch_2", "switch player"), central_widget)),
    btn_timer_1(new QPushButton(QApplication::translate("btn_timer_1", "120 sec"), central_widget)),
    btn_timer_2(new QPushButton(QApplication::translate("btn_timer_2", "5 min"), central_widget)),
    btn_start(new QPushButton(QApplication::translate("btn_start", "Start"), central_widget)),
    btn_stop(new QPushButton(QApplication::translate("btn_stop", "Stop"), central_widget)),

    lbl_info(new QLabel(QApplication::translate("lbl_num1", ""), central_widget)),

    player1_time(0),
    player2_time(0),
    current_player(0),
    game_time(0),

    timer(new QTimer(central_widget))
{
    ui->setupUi(this);
    resize(400, 400);
    setCentralWidget(central_widget);

    // ----- Set positions ----- TODO: add a proper layout?
    bar_player_1->move(50, 50);
    bar_player_2->move(300, 50);

    btn_switch_1->move(50, 75);
    btn_switch_2->move(300, 75);

    lbl_info->move(100, 150);

    btn_timer_1->move(100, 175);
    btn_timer_2->move(200, 175);

    btn_start->move(75, 225);
    btn_stop->move(225, 225);


    // ----- Init timer buttons and add to group -----
    btn_group_timers->addButton(btn_timer_1);
    btn_group_timers->addButton(btn_timer_2);
    btn_group_timers->setExclusive(true);
    btn_timer_1->setCheckable(true);
    btn_timer_2->setCheckable(true);


    // ----- Connect buttons -----
    connect(btn_switch_1, &QPushButton::clicked, this, &MainWindow::btn_pressed);
    connect(btn_switch_2, &QPushButton::clicked, this, &MainWindow::btn_pressed);
    connect(btn_timer_1, &QPushButton::clicked, this, &MainWindow::btn_pressed);
    connect(btn_timer_2, &QPushButton::clicked, this, &MainWindow::btn_pressed);
    connect(btn_start, &QPushButton::clicked, this, &MainWindow::btn_pressed);
    connect(btn_stop, &QPushButton::clicked, this, &MainWindow::btn_pressed);

    // ----- Init timer -----
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);
    timer->stop();

    stop_game();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if(current_player == 1)
    {
        --player1_time;
        if(player1_time <= 0)
        {
            btn_switch_2->setDisabled(true);
            btn_switch_1->setDisabled(true);
            btn_timer_1->setDisabled(true);
            btn_timer_2->setDisabled(true);
            btn_start->setDisabled(true);
            btn_stop->setDisabled(false);
            set_game_info_text("Timeout! Player 2 won.", 10);
        }
    }
    else
    {
        --player2_time;
        if(player2_time <= 0)
        {
            btn_switch_2->setDisabled(true);
            btn_switch_1->setDisabled(true);
            btn_timer_1->setDisabled(true);
            btn_timer_2->setDisabled(true);
            btn_start->setDisabled(true);
            btn_stop->setDisabled(false);
            set_game_info_text("Timeout! Player 1 won.", 10);
        }
    }

    update_progressbar();
}

void MainWindow::update_progressbar()
{
    bar_player_1->setValue(player1_time);
    bar_player_2->setValue(player2_time);
}

void MainWindow::set_game_info_text(QString txt, short font_size)
{
    QFont current = lbl_info->font();
    current.setBold(true);
    current.setPointSize(font_size);

    lbl_info->setFont(current);
    lbl_info->setText(txt);
    lbl_info->adjustSize();
}

void MainWindow::start_game()
{
    // Reset game time
    if(btn_timer_1->isChecked())
        game_time = btn_timer_1_val_seconds;
    else
        game_time = btn_timer_2_val_seconds;

    bar_player_1->setMinimum(0);
    bar_player_1->setMaximum(game_time);
    bar_player_2->setMinimum(0);
    bar_player_2->setMaximum(game_time);

    player1_time = game_time;
    player2_time = game_time;
    update_progressbar();

    if(current_player == 1)
    {
        btn_switch_2->setDisabled(true);
        btn_switch_1->setDisabled(false);
    }
    else
    {
        btn_switch_2->setDisabled(false);
        btn_switch_1->setDisabled(true);
    }

    btn_timer_1->setDisabled(true);
    btn_timer_2->setDisabled(true);
    btn_start->setDisabled(true);
    btn_stop->setDisabled(false);

    timer->start(1000);
}

void MainWindow::stop_game()
{
    if(current_player == 1)
    {
        btn_switch_2->setDisabled(true);
        btn_switch_1->setDisabled(true);
    }
    else
    {
        btn_switch_2->setDisabled(true);
        btn_switch_1->setDisabled(true);
    }

    btn_timer_1->setDisabled(false);
    btn_timer_2->setDisabled(false);
    btn_stop->setDisabled(true);

    if(btn_group_timers->checkedButton())
        btn_start->setDisabled(false);
    else
        btn_start->setDisabled(true);

    timer->stop();

    set_game_info_text("Select game time.", 10);
}

void MainWindow::btn_pressed()
{
    QPushButton* button = (QPushButton*)sender();
    if (!button)
        return;

    if(button == btn_switch_1)
    {
        // Switch to player 2's turn
        current_player = 2;

        btn_switch_1->setDisabled(true);
        btn_switch_2->setDisabled(false);
    }
    else if(button == btn_switch_2)
    {
        // Switch to player 1's turn
        current_player = 1;

        btn_switch_1->setDisabled(false);
        btn_switch_2->setDisabled(true);
    }
    else if(button == btn_timer_1)
    {
        game_time = btn_timer_1_val_seconds;
        btn_start->setDisabled(false);
    }
    else if(button == btn_timer_2)
    {
        game_time = btn_timer_2_val_seconds;
        btn_start->setDisabled(false);
    }
    else if(button == btn_start)
    {
        set_game_info_text("Game in progress...", 10);
        start_game();
    }
    else if(button == btn_stop)
    {
        stop_game();
    }
}
