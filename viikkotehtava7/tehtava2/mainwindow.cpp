#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    central_widget(new QWidget(this)),
    layout(new QGridLayout (central_widget)),

    lbl_num_1(new QLabel(QApplication::translate("lbl_num1", "Number 1"), central_widget)),
    lbl_num_2(new QLabel(QApplication::translate("lbl_num2", "Number 2"), central_widget)),
    lbl_res(new QLabel(QApplication::translate("lbl_res", "Result"), central_widget)),

    le_num_1(new QLineEdit(QApplication::translate("le_num1", ""), central_widget)),
    le_num_2(new QLineEdit(QApplication::translate("le_num2", ""), central_widget)),
    le_res(new QLineEdit(QApplication::translate("le_res", ""), central_widget)),

    btn_add(new QPushButton(QApplication::translate("btn_add", "+"), central_widget)),
    btn_sub(new QPushButton(QApplication::translate("btn_sub", "-"), central_widget)),
    btn_mul(new QPushButton(QApplication::translate("btn_mul", "*"), central_widget)),
    btn_div(new QPushButton(QApplication::translate("btn_div", "/"), central_widget)),

    btn_clear(new QPushButton(QApplication::translate("btn_clear", "Clear"), central_widget)),
    btn_enter(new QPushButton(QApplication::translate("btn_enter", "Enter"), central_widget)),

    btn_0(new QPushButton(QApplication::translate("btn_0", "0"), central_widget)),
    btn_1(new QPushButton(QApplication::translate("btn_1", "1"), central_widget)),
    btn_2(new QPushButton(QApplication::translate("btn_2", "2"), central_widget)),
    btn_3(new QPushButton(QApplication::translate("btn_3", "3"), central_widget)),
    btn_4(new QPushButton(QApplication::translate("btn_4", "4"), central_widget)),
    btn_5(new QPushButton(QApplication::translate("btn_5", "5"), central_widget)),
    btn_6(new QPushButton(QApplication::translate("btn_6", "6"), central_widget)),
    btn_7(new QPushButton(QApplication::translate("btn_7", "7"), central_widget)),
    btn_8(new QPushButton(QApplication::translate("btn_8", "8"), central_widget)),
    btn_9(new QPushButton(QApplication::translate("btn_9", "9"), central_widget)),

    operation('\0'),
    le_active(le_num_1)
{
    ui->setupUi(this);
    resize(300, 100);
    setCentralWidget(central_widget);

    // Add row 0
    layout->addWidget(lbl_num_1, 0, 0);
    layout->addWidget(lbl_num_2, 0, 1);
    layout->addWidget(lbl_res, 0, 2);

    // Add row 1
    layout->addWidget(le_num_1, 1, 0);
    layout->addWidget(le_num_2, 1, 1);
    layout->addWidget(le_res, 1, 2);

    // Add row 2
    layout->addWidget(btn_1, 2, 0);
    layout->addWidget(btn_2, 2, 1);
    layout->addWidget(btn_3, 2, 2);
    layout->addWidget(btn_add, 2, 3);

    // Add row 3
    layout->addWidget(btn_4, 3, 0);
    layout->addWidget(btn_5, 3, 1);
    layout->addWidget(btn_6, 3, 2);
    layout->addWidget(btn_sub, 3, 3);

    // Add row 4
    layout->addWidget(btn_7, 4, 0);
    layout->addWidget(btn_8, 4, 1);
    layout->addWidget(btn_9, 4, 2);
    layout->addWidget(btn_mul, 4, 3);

    // Add row 5
    layout->addWidget(btn_0, 5, 0);
    layout->addWidget(btn_clear, 5, 1);
    layout->addWidget(btn_enter, 5, 2);
    layout->addWidget(btn_div, 5, 3);

    setLayout(layout);
    setWindowTitle(QApplication::translate("window", "Tehtava 1"));

    connect(btn_add, &QPushButton::clicked, this, &MainWindow::operation_btn_pressed);
    connect(btn_sub, &QPushButton::clicked, this, &MainWindow::operation_btn_pressed);
    connect(btn_mul, &QPushButton::clicked, this, &MainWindow::operation_btn_pressed);
    connect(btn_div, &QPushButton::clicked, this, &MainWindow::operation_btn_pressed);

    connect(btn_clear, &QPushButton::clicked, this, &MainWindow::clear_enter_btn_pressed);
    connect(btn_enter, &QPushButton::clicked, this, &MainWindow::clear_enter_btn_pressed);

    connect(btn_0, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_1, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_2, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_3, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_4, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_5, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_6, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_7, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_8, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
    connect(btn_9, &QPushButton::clicked, this, &MainWindow::number_btn_pressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show()
{
    ((QMainWindow*)this)->show();
}

void MainWindow::operation_btn_pressed()
{
    QPushButton* button = (QPushButton*)sender();
    if (!button)
        return;

    operation = button->text().toStdString()[0];
    if(le_active == le_num_1)
        le_active = le_num_2;
}

void MainWindow::clear_enter_btn_pressed()
{
    QPushButton* button = (QPushButton*)sender();
    if (!button)
        return;

    if(button == btn_clear)
    {
        le_num_1->setText("");
        le_num_2->setText("");
        le_res->setText("");

        le_active = le_num_1;
    }
    else if(button == btn_enter && le_active == le_num_2)
    {
        int num_1 = le_num_1->text().toInt();
        int num_2 = le_num_2->text().toInt();

        switch(operation)
        {
            case '+':
                le_res->setText(QString::number(num_1 + num_2));
                break;

            case '-':
                le_res->setText(QString::number(num_1 - num_2));
                break;

            case '*':
                le_res->setText(QString::number(num_1 * num_2));
                break;
            case '/':
                if(num_2 != 0)
                    le_res->setText(QString::number(num_1 / num_2));
                else
                    le_res->setText("NULL");
                break;
        }

        le_active = le_res;
    }
}

void MainWindow::number_btn_pressed()
{
    QPushButton* button = (QPushButton*)sender();
    if (!button)
        return;

    if(le_active == le_num_1 || le_active == le_num_2)
    {
        QString num = le_active->text();
        num.append(button->text().at(0));
        le_active->setText(num);
    }
}
