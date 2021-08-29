#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QObject>

const QString HOST = "localhost";
const QString USER = "paul";
const QString PW   = "master";
const QString DB   = "Polizzen";

class DataBase
{
public:
    explicit DataBase();
    ~DataBase();

    bool connectToDatabase();
    QString getUser();
    QString getPw();
    QString getDatabase();
    QString getHost();
    QString ErrorMessage;

protected:
    QSqlDatabase db;


signals:

public slots:
private:

    QString connectionname;

};

#endif // DATABASE_H
