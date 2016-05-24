#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QDebug>

class Log : public QObject
{
    Q_OBJECT
public:
    explicit Log(QObject *parent = 0);

signals:

public slots:
    void insertLog();
};

#endif // LOG_H
