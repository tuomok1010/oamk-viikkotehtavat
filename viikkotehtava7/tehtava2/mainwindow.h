#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGridLayout;
class QLabel;
class QPushButton;
class QLineEdit;

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void show();

private:
    Ui::MainWindow* ui;
    QWidget* central_widget;
    QGridLayout* layout;

    QLabel* lbl_num_1;
    QLabel* lbl_num_2;
    QLabel* lbl_res;

    QLineEdit* le_num_1;
    QLineEdit* le_num_2;
    QLineEdit* le_res;

    QPushButton* btn_add;
    QPushButton* btn_sub;
    QPushButton* btn_mul;
    QPushButton* btn_div;

    QPushButton* btn_clear;
    QPushButton* btn_enter;

    QPushButton* btn_0;
    QPushButton* btn_1;
    QPushButton* btn_2;
    QPushButton* btn_3;
    QPushButton* btn_4;
    QPushButton* btn_5;
    QPushButton* btn_6;
    QPushButton* btn_7;
    QPushButton* btn_8;
    QPushButton* btn_9;

    char operation;
    QLineEdit* le_active;

private slots:
    void operation_btn_pressed();
    void clear_enter_btn_pressed();
    void number_btn_pressed();
};
#endif // MAINWINDOW_H
