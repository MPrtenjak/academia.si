#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QMessageBox>
#include "loginmanager.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    setupUI();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::setupUI()
{
    setWindowTitle("Login");
    setFixedSize(360, 200);
    // setBaseSize(360, 200);

    userLabel = new QLabel("User name", this);
    userLabel->setGeometry(20, 20, 100, 24);

    userEdit = new QLineEdit(this);
    userEdit->setGeometry(130, 20, 200, 24);

    passLabel = new QLabel("Password", this);
    passLabel->setGeometry(20, 60, 100, 24);

    passEdit = new QLineEdit(this);
    passEdit->setGeometry(130, 60, 200, 24);
    passEdit->setEchoMode(QLineEdit::Password);

    cancelButton = new QPushButton("Cancel", this);
    cancelButton->setGeometry(130, 120, 95, 30);

    loginButton = new QPushButton("Login", this);
    loginButton->setGeometry(235, 120, 95, 30);

    connect(cancelButton, &QPushButton::clicked,
            this, &LoginWindow::onCancelPressed);

    connect(loginButton, &QPushButton::clicked,
            this, &LoginWindow::onLoginPressed);
}

void LoginWindow::onCancelPressed()
{
    close();
}

void LoginWindow::onLoginPressed()
{
    LoginManager loginManager(userEdit->text(), passEdit->text());

    if (loginManager.canILogin()) {
        QMessageBox::information(this, "Login", "You have successfuly loged in");
    }
    else {
        QMessageBox::critical(this, "Login", "User name or passwor is wrong!");
    }
}
