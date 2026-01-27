#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void onCancelPressed();
    void onLoginPressed();

private:
    Ui::LoginWindow *ui;

    QLabel* userLabel = nullptr;
    QLineEdit* userEdit = nullptr;

    QLabel* passLabel = nullptr;
    QLineEdit* passEdit = nullptr;

    QPushButton* cancelButton = nullptr;
    QPushButton* loginButton = nullptr;

    void setupUI();
};

#endif // LOGINWINDOW_H
