#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <token.h>

using std::string;


QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    void MostrarInventario();
    void LogIn();
    void MostrarSalidas();
    void RegistrarEmpleado(QString id, QString nombre, QString contra, QString puesto);
    std::string LeerToken();
    void MostrarEntradas();
    void ActualizarTablas();
    bool ModificarInsumo(int cantidad);
    QString BuscarPorCodigo(QString codigo);
    int obtenerPrimaryKey();
    bool RestarInsumo(int cantidad);
    ~cframe();

private slots:
    void on_botonlogearse_clicked();

    void on_AgregarProducto_clicked();

    void on_pushButton_clicked();

    void on_Btn_restar_clicked();

    void on_CerrarSesion_clicked();

    void on_CerrarSesion_3_clicked();

    void on_CerrarSesion_2_clicked();

    void on_TokenBtn_clicked();

private:
    void LimpiarEspacios();
    Ui::cframe *ui;
    void setupDatabase();
    void createTable();
    Token a;
    void insertValues();
    void queryTable();
    int CantInventario;
};

#endif // CFRAME_H
