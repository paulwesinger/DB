#include "database.h"

#include <QSqlError>

DataBase::DataBase()
{

}

DataBase::~DataBase() {

}

bool DataBase::connectToDatabase() {

    db = QSqlDatabase::addDatabase("QMYSQL",connectionname);
    db.setDatabaseName(DB);
    db.setHostName(HOST);
    db.setUserName(USER);
    db.setPassword(PW);

    if ( db.open())
        return true;
    else
    {

       ErrorMessage = QSqlError(db.lastError()).text();

        return false;
    }
}

QString DataBase::getPw()   { return PW;    }
QString DataBase::getHost() { return HOST;  }
QString DataBase::getUser() { return USER;  }
QString DataBase::getDatabase() {return DB;}
