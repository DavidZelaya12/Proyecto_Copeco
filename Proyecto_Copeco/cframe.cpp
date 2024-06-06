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
    ActualizarTablas();
    ui->tabCentral->setTabEnabled(1, false);
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

void cframe::LogIn()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM personas")) {
        while (query.next()) {
            std::string contraDB, contraLog, tokencrip, contraingresada, nombre, nombreDB;
            QString tokenS;
            contraingresada = ui->txcontrasea->text().toStdString();
            contraDB = query.value(2).toString().toStdString();
            if(contraingresada.size()>7){
                nombre=ui->txtusuario->text().toStdString();
                nombreDB = query.value(1).toString().toStdString();
                contraLog = contraingresada.substr(0, contraingresada.size()-6);
                tokenS = QString::fromStdString(contraingresada.substr(contraingresada.size()-6, contraingresada.size()));
                tokencrip= a.EncriptarToken(tokenS.toLong());
                //QMessageBox::critical(this, "Error", QString::fromStdString(contraDB+" "+contraLog+" "+tokenS.toStdString()+" "+tokencrip+" "+LeerToken()+" "+nombre+" "+nombreDB));
                if(contraDB==contraLog && tokencrip==LeerToken() && nombre==nombreDB){
                    ui->tabCentral->setTabEnabled(1,true);
                    ui->tabCentral->setCurrentIndex(1);
                    ui->tabCentral->setTabEnabled(0,false);
                    return;
                }
            }
        }
    }
    QMessageBox::critical(this, "Error", "Verifque sus credenciales de inicio de sesion");
}

void cframe::MostrarSalidas()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM ES ORDER BY fecha")) {
        ui->TablesEntradas_2->setRowCount(0);
        ui->TablesEntradas_2->setColumnCount(8);
        QStringList headers = {"ID", "Codigo", "Nombre", "Cantidad", "Accion", "Fecha", "Remitente", "Receptor"};
        ui->TablesEntradas_2->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            ui->TablesEntradas_2->insertRow(row);

            int id = query.value(0).toInt();
            QString codigo = query.value(1).toString();
            QString nombre = query.value(2).toString();
            int cantidad = query.value(3).toInt();
            QString accion = query.value(4).toString();
            QString fecha = query.value(5).toString();
            QString remitente = query.value(6).toString();
            QString receptor = query.value(7).toString();

            ui->TablesEntradas_2->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->TablesEntradas_2->setItem(row, 1, new QTableWidgetItem(codigo));
            ui->TablesEntradas_2->setItem(row, 2, new QTableWidgetItem(nombre));
            ui->TablesEntradas_2->setItem(row, 3, new QTableWidgetItem(QString::number(cantidad)));
            ui->TablesEntradas_2->setItem(row, 4, new QTableWidgetItem(accion));
            ui->TablesEntradas_2->setItem(row, 5, new QTableWidgetItem(fecha));
            ui->TablesEntradas_2->setItem(row, 6, new QTableWidgetItem(remitente));
            ui->TablesEntradas_2->setItem(row, 7, new QTableWidgetItem(receptor));

            row++;
        }
    } else {
        QMessageBox::critical(this, "Query Execution Error", query.lastError().text());
    }
}

void cframe::MostrarEntradas()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM ES ORDER BY fecha")) {
        ui->TablesEntradas->setRowCount(0);
        ui->TablesEntradas->setColumnCount(8);
        QStringList headers = {"ID", "Codigo", "Nombre", "Cantidad", "Accion", "Fecha", "Remitente", "Receptor"};
        ui->TablesEntradas->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            ui->TablesEntradas->insertRow(row);

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
    MostrarEntradas();
}

bool cframe::ModificarInsumo(int cantidad)
{
  //  QString nombreProducto = ui->NombreAgregar->text();
    QString CodigoProducto = ui->CodigoEntrada->text();
    QSqlQuery query;

    if(BuscarPorCodigo(CodigoProducto)=="no"){
        QMessageBox::critical(this, "Error", "Codigo inexistente");
        return false;
    }

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
            QMessageBox::critical(this, "Error no existe", query.lastError().text());
        } else {
            QMessageBox::information(this, "Update Successful", "Cantidad actualizada exitosamente.");
            ActualizarTablas();
            return true;
        }
    }else{
        return false;
    }

}

QString cframe::BuscarPorCodigo(QString codigo)
{
    QSqlQuery query;
    QString nombreProducto;

    // Consulta para obtener el nombre del producto basado en el código
    QString selectSql = "SELECT nombre FROM inventario WHERE Codigo = :codigo";
    query.prepare(selectSql);
    query.bindValue(":codigo", codigo);

    if (!query.exec()) {
       // QMessageBox::critical(nullptr, "Query Error", query.lastError().text());
        return "no funca"; // Retorna una cadena vacía en caso de error
    }

    if (query.next()) {
        nombreProducto = query.value(0).toString();
    } else {
       // QMessageBox::information(nullptr, "No Result", "No se encontró un producto con el código especificado.");
        return "no";
    }

    return nombreProducto;
}

bool cframe::RestarInsumo(int cantidad)
{
    QString nombreProducto = ui->NombreAgregar->text();
    QString CodigoProducto = ui->CodigoSalida->text();
    QSqlQuery query;


    QString selectSql = "SELECT Cantidad FROM inventario WHERE Codigo = :CodigoProducto";
    query.prepare(selectSql);
    query.bindValue(":CodigoProducto", CodigoProducto);

    if(BuscarPorCodigo(CodigoProducto)=="no"){
        QMessageBox::critical(this, "Error", "Codigo inexistente");
        return false;
    }


    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        return false;
    }

    if (query.next()) {
        // Producto existe, restar cantidad X
        int currentCantidad = query.value(0).toInt();
        int nuevaCantidad = currentCantidad - cantidad;

        if (cantidad > currentCantidad) {
            QMessageBox::critical(this, "Update Error", "Cantidad insuficiente en inventario.");
            return false;
        }

        QString updateSql = "UPDATE inventario SET Cantidad = :nuevaCantidad WHERE Codigo = :CodigoProducto";
        query.prepare(updateSql);
        query.bindValue(":nuevaCantidad", nuevaCantidad);
        query.bindValue(":CodigoProducto", CodigoProducto);

        if (!query.exec()) {
            QMessageBox::critical(this, "Update Error", query.lastError().text());
            return false;
        } else {
            QMessageBox::information(this, "Update Successful", "Cantidad restada exitosamente.");
            ActualizarTablas();
            return true;
        }
    } else {
        QMessageBox::critical(this, "Query Error", "Producto no encontrado en el inventario.");
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
/*
void cframe::createTable()
{
    QSqlQuery query;
    QString createTableSql = R"(
        CREATE TABLE personas(
            ID NVARCHAR(13) PRIMARY KEY,
            nombre NVARCHAR(50),
            contra NVARCHAR(15),
            puesto NVARCHAR(15),
        )
    )";

    if (!query.exec(createTableSql)) {
        QMessageBox::critical(this, "Table Creation Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Table Creation", "Table 'personas' created successfully.");
    }
}
*/
void cframe::insertValues()
{
    QSqlQuery query;
    QString insertValuesSql = R"(
        INSERT INTO personas (id, nombre, contra, puesto) VALUES
        ('0501199067890', 'Virgilio Fuentes', 'virgigod', 'Bodeguero')
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
    if(ui->txcontrasea->text()!="" && ui->txtusuario->text()!="")
        LogIn();
    else
        QMessageBox::critical(this, "Error", "Rellene todos los espacios");
}


void cframe::on_AgregarProducto_clicked()
{
    std::cout<<std::endl<<CantInventario<<std::endl;
    QString nombreProducto = ui->NombreAgregar->text();
    QString CodigoProducto = ui->CodigoAgregar->text();

    if(CodigoProducto.length() != 4){
        QMessageBox::critical(this, "Error", "Codigo invalido");
        return;
    }


    QSqlQuery query;
    QString insertValuesSql = "INSERT INTO inventario (Codigo, nombre, Cantidad) VALUES(:CodigoProducto, :nombreProducto, 0)";
    query.prepare(insertValuesSql);
    query.bindValue(":nombreProducto", nombreProducto);
    query.bindValue(":CodigoProducto", CodigoProducto);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Verifique la informacion de sus campos");
    } else {
        QMessageBox::information(this, "Exito", "Insumo agregado exitosamente!.");
        ActualizarTablas();
    }
    ui->NombreAgregar->text().clear();
    ui->CodigoAgregar->text().clear();
}


void cframe::on_pushButton_clicked()
{
    ModificarInsumo(ui->cantidadentrada->value());
    std::cout<<std::endl<<CantInventario<<std::endl;
    QString CodigoProducto = ui->CodigoEntrada->text();
    QString nombreProducto = BuscarPorCodigo(CodigoProducto);
    QString cantidad= ui->cantidadentrada->text();
    QString remitentes = ui->NombreRemitente->text();
    QString recibe = ui->ResponsableEntrada->text();
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    if(BuscarPorCodigo(CodigoProducto)=="no"){
        QMessageBox::critical(this, "Error", "Codigo inexistente");
        return ;
    }

    // Convertir el tiempo a una estructura tm de manera segura
    std::tm now_tm;
    localtime_r(&now_time, &now_tm);

    // Usar ostringstream para formatear la fecha en dd/MM/yyyy
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%d/%m/%Y");
    std::string fec = oss.str();
    QString fecha = QString::fromStdString(fec);

    QSqlQuery query;
    QString insertValuesSql = "INSERT INTO ES (codigo, nombre, cantidad, accion, fecha, remitente, recibe) VALUES(:codigo, :nombreProducto, :cantidad, 'Entrada', :fecha, :remitentes, :recibe)";
    query.prepare(insertValuesSql);
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



void cframe::on_Btn_restar_clicked()
{
    RestarInsumo(ui->CantidadSalida->value());
    std::cout<<std::endl<<CantInventario<<std::endl;
    QString CodigoProducto = ui->CodigoSalida->text();
    QString nombreProducto = BuscarPorCodigo(CodigoProducto);
    QString cantidad= ui->CantidadSalida->text();
    QString remitentes = ui->ResponsableSalida->text();
    QString recibe = ui->RecibioSalida->text();
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    if(BuscarPorCodigo(CodigoProducto)=="no"){
        QMessageBox::critical(this, "Error", "Codigo inexistente");
        return ;
    }

    // Convertir el tiempo a una estructura tm de manera segura
    std::tm now_tm;
    localtime_r(&now_time, &now_tm);

    // Usar ostringstream para formatear la fecha en dd/MM/yyyy
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%d/%m/%Y");
    std::string fec = oss.str();
    QString fecha = QString::fromStdString(fec);

    QSqlQuery query;
    QString insertValuesSql = "INSERT INTO ES (codigo, nombre, cantidad, accion, fecha, remitente, recibe) VALUES(:codigo, :nombreProducto, :cantidad, 'Salida', :fecha, :remitentes, :recibe)";
    query.prepare(insertValuesSql);
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



void cframe::on_CerrarSesion_clicked()
{
    ui->tabCentral->setTabEnabled(0,true);
    ui->tabCentral->setCurrentIndex(0);
    ui->tabCentral->setTabEnabled(1,false);
}


void cframe::on_CerrarSesion_3_clicked()
{
    ui->tabCentral->setTabEnabled(0,true);
    ui->tabCentral->setCurrentIndex(0);
    ui->tabCentral->setTabEnabled(1,false);
}


void cframe::on_CerrarSesion_2_clicked()
{
    ui->tabCentral->setTabEnabled(0,true);
    ui->tabCentral->setCurrentIndex(0);
    ui->tabCentral->setTabEnabled(1,false);
}

void cframe::on_TokenBtn_clicked()
{
    a.SetToken(a.GenerarToken());
    a.show();
}

std::string cframe::LeerToken()
{
    std::ifstream Archivo("token_cifrado.txt");
    if (Archivo.is_open())
    {
        std::string token;
        std::getline(Archivo, token);
        Archivo.close();
        return token;
    }
    else
    {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo token_cifrado.txt");
        return NULL;
    }
}

