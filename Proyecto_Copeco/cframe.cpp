#include "cframe.h"
#include "ui_cframe.h"

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);

    setupDatabase();
    createTable();
    insertValues();
    queryTable();
    OnyOff(false);

}

void cframe::OnyOff(bool accion)
{
    ui->TabMostrar->setVisible(accion);
    ui->TabIngresar->setTabEnabled(2,accion);
    ui->TabIngresar->setTabEnabled(1,accion);
}

cframe::~cframe()
{
    delete ui;
}



void cframe::setupDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString serverName = "copecoserver.database.windows.net";
    QString dbName = "copecoDB";
    QString username = "eladmin";
    QString password = "Copeco123";

    QString connectionString = QString("Driver={ODBC Driver 18 for SQL Server};Server=tcp:%1,1433;Database=%2;Uid=%3;"
                                       "Pwd=%4;Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;")
                               .arg(serverName).arg(dbName).arg(username).arg(password);
    db.setDatabaseName(connectionString);

    if (!db.open()) {
        QMessageBox::critical(this, "Database Connection Error", db.lastError().text());
    } else {
        QMessageBox::information(this, "Database Connection", "Successfully connected to the database!");
    }
}

void cframe::createTable()
{
    QSqlQuery query;
    QString createTableSql = R"(
        CREATE TABLE personas (
            id INT PRIMARY KEY,
            dni NVARCHAR(13),
            nombre NVARCHAR(50),
            puesto NVARCHAR(50)
        )
    )";

    if (!query.exec(createTableSql)) {
        QMessageBox::critical(this, "Table Creation Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Table Creation", "Table 'personas' created successfully.");
    }
}

void cframe::insertValues()
{
    QSqlQuery query;
    QString insertValuesSql = R"(
        INSERT INTO personas (id, dni, nombre, puesto) VALUES
        (1, '0501199012345', 'Omar Cuz', 'Bodeguero')
    )";

    if (!query.exec(insertValuesSql)) {
        QMessageBox::critical(this, "Insert Values Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Insert Values", "Values inserted into 'personas' table successfully.");
    }
}

void cframe::queryTable()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM personas")) {
        while (query.next()) {
            int id = query.value(0).toInt();
            QString dni = query.value(1).toString();
            QString name = query.value(2).toString();
            QString position = query.value(3).toString();
            qDebug() << "ID:" << id << ", DNI:" << dni << ", Nombre:" << name << ", Puesto:" << position;
        }
    } else {
        QMessageBox::critical(this, "Query Execution Error", query.lastError().text());
    }
}


void cframe::on_botonlogearse_clicked()
{

    if(true){
        OnyOff(true);
    }

}

