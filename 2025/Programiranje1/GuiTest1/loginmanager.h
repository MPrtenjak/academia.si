#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QString>
#include <map>

class LoginManager
{
public:
    LoginManager(QString _userName, QString _password);

    bool canILogin();

private:
    QString userName;
    QString password;

    std::map<QString, QString> users; // username -> password

    bool readFromDisk();

};

#endif // LOGINMANAGER_H
