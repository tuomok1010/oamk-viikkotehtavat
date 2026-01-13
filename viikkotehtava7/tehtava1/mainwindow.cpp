#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    central_widget(new QWidget(this)),
    layout(new QGridLayout (central_widget)),
    count_button(new QPushButton(QApplication::translate("count_button", "Count"), central_widget)),
    reset_button(new QPushButton(QApplication::translate("reset_button", "Reset"), central_widget)),
    num_display_area(new QLineEdit(QApplication::translate("num_display_area", "0"), central_widget))
{
    ui->setupUi(this);
    resize(300, 100);
    setCentralWidget(central_widget);

    layout->addWidget(count_button, 0, 0);
    layout->addWidget(reset_button, 1, 0);
    layout->addWidget(num_display_area, 0, 1);

    setLayout(layout);
    setWindowTitle(QApplication::translate("window", "Tehtava 1"));

    connect(count_button,  &QPushButton::clicked, this, &MainWindow::button_pressed);
    connect(reset_button,  &QPushButton::clicked, this, &MainWindow::button_pressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show()
{
    ((QMainWindow*)this)->show();
}

void MainWindow::button_pressed()
{
    QPushButton* button = (QPushButton*)sender();
    if (!button)
        return;

    if(button == count_button)
    {
        int num = num_display_area->text().toInt();
        ++num;
        num_display_area->setText(QString::number(num));
    }
    else if(button == reset_button)
    {
        num_display_area->setText(QString::number(0));
    }
}
