#include "passwordchange.h"
#include "ui_passwordchange.h"

#include <QMessageBox>

PasswordChange::PasswordChange(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PasswordChange)
{
    ui->setupUi(this);

    setupUI();
}

PasswordChange::~PasswordChange()
{
    delete ui;
}

void PasswordChange::setupUI()
{
    setWindowTitle("Login");
    setFixedSize(360, 200);
    // setBaseSize(360, 200);

    int elementHeight = 24;
    int elementBottomPadding = 10;
    int elementLeftPadding = 10;
    int labelWidth = 100;
    int editWidth = 200;
    int startTop = 20;
    int startLeft = 20;

    oldPassLabel = new QLabel("Old password", this);
    oldPassLabel->setGeometry(startLeft, startTop, labelWidth, elementHeight);
    oldPassEdit = new QLineEdit(this);
    oldPassEdit->setGeometry(startLeft + labelWidth + elementLeftPadding, startTop, editWidth, elementHeight);
    oldPassEdit->setEchoMode(QLineEdit::Password);

    startTop += elementHeight + elementBottomPadding;
    pass1Label = new QLabel("New password 1", this);
    pass1Label->setGeometry(startLeft, startTop, labelWidth, elementHeight);
    pass1Edit = new QLineEdit(this);
    pass1Edit->setGeometry(startLeft + labelWidth + elementLeftPadding, startTop, editWidth, elementHeight);
    pass1Edit->setEchoMode(QLineEdit::Password);

    startTop += elementHeight + elementBottomPadding;
    pass2Label = new QLabel("New password 2", this);
    pass2Label->setGeometry(startLeft, startTop, labelWidth, elementHeight);
    pass2Edit = new QLineEdit(this);
    pass2Edit->setGeometry(startLeft + labelWidth + elementLeftPadding, startTop, editWidth, elementHeight);
    pass2Edit->setEchoMode(QLineEdit::Password);

    int buttonWidth = 120;
    int buttonHeight = 30;
    startTop += elementHeight + 3 * elementBottomPadding;
    cancelButton = new QPushButton("Cancel", this);
    cancelButton->setGeometry(startLeft, startTop, buttonWidth, buttonHeight);

    int rightBorder = startLeft + labelWidth + elementLeftPadding + editWidth;
    okButton = new QPushButton("Change", this);
    okButton->setGeometry(rightBorder - buttonWidth, startTop, buttonWidth, buttonHeight);

    connect(cancelButton, &QPushButton::clicked,
            this, &PasswordChange::onCancelPressed);

    connect(okButton, &QPushButton::clicked,
            this, &PasswordChange::onChangePressed);
}

void PasswordChange::onCancelPressed()
{
    close();
}

void PasswordChange::onChangePressed()
{
    if ((oldPassEdit->text() == "oldPass") && (pass1Edit->text() == pass2Edit->text()))
        QMessageBox::information(this, "Login", "You have successfuly changed passwor");
    else
        QMessageBox::critical(this, "Login", "Can't change password!");
}
