#include "log.h"
#include "initdb.h"

#include <QtSql>
#include <QDate>

Log::Log(QObject *parent) :
    QObject(parent)
{
}

void Log::insertLog()
{
    initDb();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.open();
    QSqlQuery q;
    //create table logs(id integer primary key, title varchar, log text, date timestamp)
    q.prepare(QLatin1String("insert into logs(title, log, date) values(?, ?, ?)"));
    //if (!q.prepare(QLatin1String("insert into logs(title, log, date) values(?, ?, ?)")))
            //return q.lastError();
    addLog(q, "First Log Title", "First log", QDateTime::currentDateTime());
}
