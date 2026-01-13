#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGridLayout;
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
    QPushButton* count_button;
    QPushButton* reset_button;
    QLineEdit* num_display_area;

    private slots:
    void button_pressed();
};
#endif // MAINWINDOW_H
