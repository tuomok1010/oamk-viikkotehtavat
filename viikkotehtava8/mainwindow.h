#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QProgressBar;
class QButtonGroup;
class QPushButton;
class QLabel;
class QTimer;

static constexpr int btn_timer_1_val_seconds = 120;
static constexpr int btn_timer_2_val_seconds = 300;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void timeout();
    void update_progressbar();
    void set_game_info_text(QString txt, short font_size);
    void start_game();
    void stop_game();

    private:
    Ui::MainWindow *ui;
    QWidget* central_widget;

    QProgressBar* bar_player_1;
    QProgressBar* bar_player_2;

    QPushButton* btn_switch_1;
    QPushButton* btn_switch_2;

    QButtonGroup* btn_group_timers;
    QPushButton* btn_timer_1;
    QPushButton* btn_timer_2;

    QPushButton* btn_start;
    QPushButton* btn_stop;

    QLabel* lbl_info;

    short player1_time;
    short player2_time;
    short current_player;
    short game_time;

    QTimer* timer;

    private slots:
    void btn_pressed();
};
#endif // MAINWINDOW_H
