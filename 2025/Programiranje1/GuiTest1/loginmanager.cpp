#include "loginmanager.h"

#include <fstream>

LoginManager::LoginManager(QString _userName, QString _password)
{
    userName = _userName;
    password = _password;
}


bool LoginManager::canILogin()
{
    readFromDisk();

    QString un = userName;
    if (un.isEmpty())
        return false;

    std::map<QString, QString>::const_iterator it = users.find(un);

    if (it == users.end())
        return false;

    return it->second == password;
}

bool LoginManager::readFromDisk()
{
    users.clear();

    std::ifstream in("C:\\temp\\uporabniki.txt");
    if (!in.is_open())
        return false;

    std::string line;
    while (std::getline(in, line))
    {
        // expected line: username,password
        std::string::size_type commaPos = line.find(';');
        if (commaPos == std::string::npos)
            continue;

        QString un = QString::fromStdString(line.substr(0, commaPos)).trimmed();
        QString pw = QString::fromStdString(line.substr(commaPos + 1)).trimmed();

        if (un.isEmpty())
            continue;

        users[un] = pw;
    }

    return true;
}
