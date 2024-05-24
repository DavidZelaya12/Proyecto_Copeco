#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private:
    Ui::cframe *ui;
    void setupDatabase();
    void createTable();
    void insertValues();
    void queryTable();
};
#endif // CFRAME_H
