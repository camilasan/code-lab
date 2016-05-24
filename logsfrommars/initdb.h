#ifndef INITDB_H
#define INITDB_H

#include <QtSql>

void addLog(QSqlQuery &q, const QString &title, const QString &log, const QDateTime date)
{
    q.addBindValue(title);
    q.addBindValue(log);
    q.addBindValue(date);
    q.exec();
}

QSqlError initDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("logsfrommars.sqlite");

    if (!db.open())
        return db.lastError();

    QStringList tables = db.tables();
    if (tables.contains("logs", Qt::CaseInsensitive))
        return QSqlError();

    QSqlQuery q;
    if (!q.exec(QLatin1String("create table logs(id integer primary key, title varchar, log text, date timestamp)")))
        return q.lastError();

    return QSqlError();
}

#endif // INITDB_H
