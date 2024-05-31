#include "cframe.h"
#include "ui_cframe.h"

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);

    setupDatabase();
    //createTable();
    insertValues();
    queryTable();
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
        ui->TableInventario->setColumnCount(4); // Set the number of columns
        QStringList headers = {"ID", "Codigo", "Nombre", "Cantidad"};
        ui->TableInventario->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next()) {
            ui->TableInventario->insertRow(row); // Insert a new row

            int id = query.value(0).toInt();
            QString codigo = query.value(1).toString();
            QString nombre = query.value(2).toString();
            int cantidad = query.value(3).toInt();

            ui->TableInventario->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->TableInventario->setItem(row, 1, new QTableWidgetItem(codigo));
            ui->TableInventario->setItem(row, 2, new QTableWidgetItem(nombre));
            ui->TableInventario->setItem(row, 3, new QTableWidgetItem(QString::number(cantidad)));

            row++;
            CantInventario++;
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
        CREATE TABLE ES (
            id INT PRIMARY KEY,
            codigo NVARCHAR(4),
            nombre NVARCHAR(50),
            cantidad INT,
            accion NVARCHAR(10),
            fecha NVARCHAR(10),
            remitente NVARCHAR(50),
            recibe NVARCHAR(50)
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
    QString nombreProducto = ui->NombreAgregar->text();
    QString CodigoProducto = ui->CodigoAgregar->text();
    QSqlQuery query;
    QString insertValuesSql = "INSERT INTO inventario (id, Codigo, nombre, Cantidad) VALUES(:id, :CodigoProducto, :nombreProducto, 0)";
    query.prepare(insertValuesSql);
    query.bindValue(":id", CantInventario);
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

