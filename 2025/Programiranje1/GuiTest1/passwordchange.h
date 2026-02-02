#ifndef PASSWORDCHANGE_H
#define PASSWORDCHANGE_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class PasswordChange;
}

class PasswordChange : public QMainWindow
{
    Q_OBJECT

public:
    explicit PasswordChange(QWidget *parent = nullptr);
    ~PasswordChange();

private slots:
    void onCancelPressed();
    void onChangePressed();

private:
    Ui::PasswordChange *ui;

    QLabel* oldPassLabel = nullptr;
    QLineEdit* oldPassEdit = nullptr;

    QLabel* pass1Label = nullptr;
    QLineEdit* pass1Edit = nullptr;

    QLabel* pass2Label = nullptr;
    QLineEdit* pass2Edit = nullptr;

    QPushButton* cancelButton = nullptr;
    QPushButton* okButton = nullptr;

    void setupUI();};

#endif // PASSWORDCHANGE_H
