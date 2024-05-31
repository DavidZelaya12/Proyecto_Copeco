#include "cframe.h"
#include "ui_cframe.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
    //CantInventario = obtenerPrimaryKey();
    setupDatabase();
    //createTable();
    //insertValues();
    //queryTable();
    OnyOff(false);
    ActualizarTablas();

}

void cframe::OnyOff(bool accion)
{
    ui->TabMostrar->setVisible(accion);
    ui->TabIngresar->setTabEnabled(2,accion);
    ui->TabIngresar->setTabEnabled(1,accion);
}

void cframe::MostrarInventario()
{

    QSqlQuery query;
    if (query.exec("SELECT * FROM inventario")) {
        // Set up the QTableWidget
        ui->TableInventario->setRowCount(0); // Clear any existing rows
        ui->TableInventario->setColumnCount(3); // Set the number of columns
        QStringList headers = {"Codigo", "Nombre", "Cantidad"};
        ui->TableInventario->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            ui->TableInventario->insertRow(row); // Insert a new row

            //   int id = query.value(0).toInt();
            QString codigo = query.value(0).toString();
            QString nombre = query.value(1).toString();
            int cantidad = query.value(2).toInt();

            //  ui->TableInventario->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->TableInventario->setItem(row, 0, new QTableWidgetItem(codigo));
            ui->TableInventario->setItem(row, 1, new QTableWidgetItem(nombre));
            ui->TableInventario->setItem(row, 2, new QTableWidgetItem(QString::number(cantidad)));

            row++;
            // CantInventario++;
        }
    } else {
        QMessageBox::critical(this, "Query Execution Error", query.lastError().text());
    }
    QString countSql = "SELECT COUNT(*) FROM inventario";

}

void cframe::MostrarSalidas()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM ES")) {
        // Set up the QTableWidget
        ui->TablesEntradas->setRowCount(0); // Clear any existing rows
        ui->TablesEntradas->setColumnCount(8); // Set the number of columns
        QStringList headers = {"ID", "Codigo", "Nombre", "Cantidad", "Accion", "Fecha", "Remitente", "Receptor"};
        ui->TablesEntradas->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            ui->TablesEntradas->insertRow(row); // Insert a new row

            int id = query.value(0).toInt();
            QString codigo = query.value(1).toString();
            QString nombre = query.value(2).toString();
            int cantidad = query.value(3).toInt();
            QString accion = query.value(4).toString();
            QString fecha = query.value(5).toString();
            QString remitente = query.value(6).toString();
            QString receptor = query.value(7).toString();

            ui->TablesEntradas->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->TablesEntradas->setItem(row, 1, new QTableWidgetItem(codigo));
            ui->TablesEntradas->setItem(row, 2, new QTableWidgetItem(nombre));
            ui->TablesEntradas->setItem(row, 3, new QTableWidgetItem(QString::number(cantidad)));
            ui->TablesEntradas->setItem(row, 4, new QTableWidgetItem(accion));
            ui->TablesEntradas->setItem(row, 5, new QTableWidgetItem(fecha));
            ui->TablesEntradas->setItem(row, 6, new QTableWidgetItem(remitente));
            ui->TablesEntradas->setItem(row, 7, new QTableWidgetItem(receptor));

            row++;
        }
    } else {
        QMessageBox::critical(this, "Query Execution Error", query.lastError().text());
    }
}

void cframe::ActualizarTablas()
{
    MostrarInventario();
    MostrarSalidas();
}

bool cframe::ModificarInsumo(int cantidad)
{
    QString nombreProducto = ui->NombreAgregar->text();
    QString CodigoProducto = ui->CodigoAgregar->text();
    QSqlQuery query;

    QString selectSql = "SELECT Cantidad FROM inventario WHERE Codigo = :CodigoProducto";
    query.prepare(selectSql);
    query.bindValue(":CodigoProducto", CodigoProducto);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
    }

    if (query.next()) {
        // Producto existe, sumar cantidad X
        int currentCantidad = query.value(0).toInt();

        QString updateSql = "UPDATE inventario SET Cantidad = :nuevaCantidad WHERE Codigo = :CodigoProducto";
        query.prepare(updateSql);
        query.bindValue(":nuevaCantidad", currentCantidad + cantidad);
        query.bindValue(":CodigoProducto", CodigoProducto);

        if (!query.exec()) {
            QMessageBox::critical(this, "Update Error", query.lastError().text());
        } else {
            QMessageBox::information(this, "Update Successful", "Cantidad actualizada exitosamente.");
            ActualizarTablas();
            return true;
        }
    }else{
        return false;
    }

}

int cframe::obtenerPrimaryKey()
{
    int ultimoId = 0;
    QSqlQuery query;

    // Obtener el último valor de la columna ID
    QString selectLastIdSql = "SELECT MAX(id) FROM inventario";
    query.prepare(selectLastIdSql);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
    } else {
        if (query.next()) {
            ultimoId = query.value(0).toInt();
        }
    }

    return ultimoId;
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
        CREATE TABLE inventario(
            Codigo NVARCHAR(4) PRIMARY KEY,
            nombre NVARCHAR(50),
            Cantidad int
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
        (2, '0501199067890', 'Virgilio', 'Bodeguero')
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
        // Set up the QTableWidget
        ui->TableInventario->setRowCount(0); // Clear any existing rows
        ui->TableInventario->setColumnCount(4); // Set the number of columns
        QStringList headers = {"ID", "DNI", "Nombre", "Puesto"};
        ui->TableInventario->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            ui->TableInventario->insertRow(row); // Insert a new row

            int id = query.value(0).toInt();
            QString dni = query.value(1).toString();
            QString name = query.value(2).toString();
            QString position = query.value(3).toString();

            ui->TableInventario->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->TableInventario->setItem(row, 1, new QTableWidgetItem(dni));
            ui->TableInventario->setItem(row, 2, new QTableWidgetItem(name));
            ui->TableInventario->setItem(row, 3, new QTableWidgetItem(position));

            row++;
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


void cframe::on_AgregarProducto_clicked()
{
    std::cout<<std::endl<<CantInventario<<std::endl;
    QString nombreProducto = ui->NombreAgregar->text();
    QString CodigoProducto = ui->CodigoAgregar->text();
    QSqlQuery query;
    QString insertValuesSql = "INSERT INTO inventario (Codigo, nombre, Cantidad) VALUES(:CodigoProducto, :nombreProducto, 0)";
    query.prepare(insertValuesSql);
    query.bindValue(":nombreProducto", nombreProducto);
    query.bindValue(":CodigoProducto", CodigoProducto);

    if (!query.exec()) {
        QMessageBox::critical(this, "Insert Values Error", query.lastError().text());
        ui->NombreAgregar->text().clear();
        ui->CodigoAgregar->text().clear();
    } else {
        QMessageBox::information(this, "Insert Values", "Values inserted into 'inventario' table successfully.");
        ActualizarTablas();
    }
}


void cframe::on_pushButton_clicked()
{
    ModificarInsumo(ui->cantidadentrada->value());
    std::cout<<std::endl<<CantInventario<<std::endl;
    QString nombreProducto = ui->NombreAgregar->text();
    QString CodigoProducto = ui->CodigoAgregar->text();
    QString cantidad= ui->cantidadentrada->text();
    QString remitentes = ui->Procedencia->text();
    QString recibe = ui->ResponsableEntrada->text();
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Convertir el tiempo a una estructura tm de manera segura
    std::tm now_tm;
    localtime_r(&now_time, &now_tm);

    // Usar ostringstream para formatear la fecha en dd/MM/yyyy
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%d/%m/%Y");
    std::string fec = oss.str();
    QString fecha = QString::fromStdString(fec);

    QSqlQuery query;
    QString insertValuesSql = "INSERT INTO inventario (id, codigo, nombre, cantidad, accion, fecha, remitentes, recibe) VALUES(:id, :codigo, :nombreProducto, :cantidad, 'Entrada', :fecha, :remitentes, :recibe)";
    query.prepare(insertValuesSql);
    query.bindValue(":id", 1);
    query.bindValue(":codigo", CodigoProducto);
    query.bindValue(":nombreProducto", nombreProducto);
    query.bindValue(":cantidad", cantidad.toInt());
    query.bindValue(":fecha", fecha);
    query.bindValue(":remitentes", remitentes);
    query.bindValue(":recibe", recibe);

    if (!query.exec()) {
        QMessageBox::critical(this, "Insert Values Error", query.lastError().text());
        ui->NombreAgregar->text().clear();
        ui->CodigoAgregar->text().clear();
    } else {
        QMessageBox::information(this, "Insert Values", "Values inserted into 'inventario' table successfully.");
        ActualizarTablas();
    }

}

