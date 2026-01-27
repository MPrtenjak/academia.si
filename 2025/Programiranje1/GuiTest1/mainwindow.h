#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

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

private slots:
    void onButtonPressed();
    void onButton1Pressed();
    void onMoveTextPressed();
    void onLoginButtionPressed();

    void onTextEdited(const QString &text);

private:
    Ui::MainWindow *ui;

    QLabel* label1;
    QLabel* labels[5];
    QPushButton* button;
    QPushButton* button1;

    QLineEdit* edit;
    QPushButton* buttonEdit;

    QPushButton* loginButton;

    int counter = 0;
    int counter1 = 0;

    void setupUI();
};
#endif // MAINWINDOW_H
