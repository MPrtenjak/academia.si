#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include "LoginWindow.h"
#include "PasswordChange.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    setWindowTitle("Naše prvo okno");
    // setFixedSize(500, 250);

    setBaseSize(500, 250);

    label1= new QLabel("this is label!", this);
    label1->setGeometry(20, 20, 180, 30);
    label1->setStyleSheet(
        "background-color: yellow;"
        "qproperty-alignment: AlignCenter;"
        );

    for(int i = 0; i < 5; ++i)
    {
        labels[i]= new QLabel(QString("this is label %1").arg(i), this);
        labels[i]->setGeometry(20, 55 + 35 * i, 180, 30);
        labels[i]->setStyleSheet(
            "background-color: lightblue;"
            "qproperty-alignment: AlignCenter;"
            );

    }

    button = new QPushButton("Press me", this);
    button->setGeometry(20, 55 + 35 * 5, 180, 30);

    connect(button, &QPushButton::clicked,
            this, &MainWindow::onButtonPressed);


    button1 = new QPushButton("Klikni me", this);
    button1->setGeometry(210, 55 + 35 * 5, 180, 30);

    connect(button1, &QPushButton::clicked,
            this, &MainWindow::onButton1Pressed);


    edit = new QLineEdit(this);
    edit->setGeometry(20, 55 + 35 * 6, 180, 30);

    buttonEdit = new QPushButton("Move text", this);
    buttonEdit->setGeometry(210, 55 + 35 * 6, 180, 30);

    connect(buttonEdit, &QPushButton::clicked,
            this, &MainWindow::onMoveTextPressed);

    connect(edit, &QLineEdit::textEdited,
            this, &MainWindow::onTextEdited);


    loginButton = new QPushButton("LOGIN", this);
    loginButton->setGeometry(210, 55 + 35 * 7, 180, 30);
    connect(loginButton, &QPushButton::clicked,
            this, &MainWindow::onLoginButtionPressed);

    changePassButton = new QPushButton("Change pass", this);
    changePassButton->setGeometry(210, 55 + 35 * 8, 180, 30);
    connect(changePassButton, &QPushButton::clicked,
            this, &MainWindow::onChangeButtonPressed);
}

void MainWindow::onButtonPressed()
{
    counter++;
    label1->setText(QString("You have pressed me %1 times!").arg(counter));
}

void MainWindow::onButton1Pressed()
{
    counter1++;
    labels[counter1 % 5]->setText(QString("You have pressed me %1 times!").arg(counter1));
}

void MainWindow::onMoveTextPressed()
{
    label1->setText(edit->displayText());
    edit->setText("");
}

void MainWindow::onTextEdited(const QString &text)
{
    label1->setText(text);
    for(int i = 0; i < 5; ++i)
        labels[i]->setText(text);
}

void MainWindow::onLoginButtionPressed()
{
    //QMessageBox::critical(this, "Login", "You have pressed the login button");
    //QMessageBox::information(this, "Login", "You have pressed the login button");

    LoginWindow* loginWindow = new LoginWindow(this);

    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->show();
    loginWindow->raise();
    loginWindow->activateWindow();
}

void MainWindow::onChangeButtonPressed()
{
    PasswordChange* passwordChangeWindow = new PasswordChange(this);

    passwordChangeWindow->setAttribute(Qt::WA_DeleteOnClose);
    passwordChangeWindow->show();
    passwordChangeWindow->raise();
    passwordChangeWindow->activateWindow();
}
