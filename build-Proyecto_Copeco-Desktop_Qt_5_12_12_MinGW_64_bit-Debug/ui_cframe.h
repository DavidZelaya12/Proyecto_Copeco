/********************************************************************************
** Form generated from reading UI file 'cframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFRAME_H
#define UI_CFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cframe
{
public:
    QWidget *centralwidget;
    QTabWidget *TabIngresar;
    QWidget *tab;
    QLabel *label_3;
    QPushButton *botonlogearse;
    QLineEdit *txtusuario;
    QLineEdit *txtcontra;
    QLabel *label_4;
    QWidget *tab_2;
    QLineEdit *NombreProducto;
    QLabel *label_5;
    QLineEdit *Procedencia;
    QLabel *label_6;
    QLineEdit *ResponsableEntrada;
    QLabel *label_7;
    QLineEdit *RecibioEntrada;
    QLabel *label_8;
    QSpinBox *CantidadEntrada;
    QLabel *label_9;
    QLineEdit *CodigoEntrada;
    QLabel *label_10;
    QPushButton *pushButton;
    QWidget *tab_3;
    QLineEdit *RecibioSalida;
    QLineEdit *CodigoSalida;
    QSpinBox *CantidadSalida;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *ResponsableSalida;
    QLabel *label_22;
    QPushButton *pushButton_3;
    QTabWidget *TabMostrar;
    QWidget *widget;
    QLabel *label_2;
    QTableWidget *TableInventario;
    QWidget *tab_5;
    QTableWidget *TablesEntradas;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuCopeco;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cframe)
    {
        if (cframe->objectName().isEmpty())
            cframe->setObjectName(QString::fromUtf8("cframe"));
        cframe->resize(1297, 771);
        centralwidget = new QWidget(cframe);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TabIngresar = new QTabWidget(centralwidget);
        TabIngresar->setObjectName(QString::fromUtf8("TabIngresar"));
        TabIngresar->setGeometry(QRect(20, 10, 1221, 211));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 271, 16));
        botonlogearse = new QPushButton(tab);
        botonlogearse->setObjectName(QString::fromUtf8("botonlogearse"));
        botonlogearse->setGeometry(QRect(330, 80, 80, 25));
        txtusuario = new QLineEdit(tab);
        txtusuario->setObjectName(QString::fromUtf8("txtusuario"));
        txtusuario->setGeometry(QRect(10, 50, 271, 24));
        txtcontra = new QLineEdit(tab);
        txtcontra->setObjectName(QString::fromUtf8("txtcontra"));
        txtcontra->setGeometry(QRect(10, 130, 271, 24));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 271, 16));
        TabIngresar->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        NombreProducto = new QLineEdit(tab_2);
        NombreProducto->setObjectName(QString::fromUtf8("NombreProducto"));
        NombreProducto->setGeometry(QRect(10, 40, 271, 24));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 271, 16));
        Procedencia = new QLineEdit(tab_2);
        Procedencia->setObjectName(QString::fromUtf8("Procedencia"));
        Procedencia->setGeometry(QRect(10, 110, 271, 24));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 80, 271, 16));
        ResponsableEntrada = new QLineEdit(tab_2);
        ResponsableEntrada->setObjectName(QString::fromUtf8("ResponsableEntrada"));
        ResponsableEntrada->setGeometry(QRect(300, 40, 271, 24));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 10, 271, 16));
        RecibioEntrada = new QLineEdit(tab_2);
        RecibioEntrada->setObjectName(QString::fromUtf8("RecibioEntrada"));
        RecibioEntrada->setGeometry(QRect(300, 110, 271, 24));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(300, 80, 271, 16));
        CantidadEntrada = new QSpinBox(tab_2);
        CantidadEntrada->setObjectName(QString::fromUtf8("CantidadEntrada"));
        CantidadEntrada->setGeometry(QRect(590, 110, 46, 25));
        CantidadEntrada->setMinimum(1);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(590, 10, 271, 16));
        CodigoEntrada = new QLineEdit(tab_2);
        CodigoEntrada->setObjectName(QString::fromUtf8("CodigoEntrada"));
        CodigoEntrada->setGeometry(QRect(590, 40, 51, 24));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(590, 90, 61, 16));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 70, 80, 25));
        TabIngresar->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        RecibioSalida = new QLineEdit(tab_3);
        RecibioSalida->setObjectName(QString::fromUtf8("RecibioSalida"));
        RecibioSalida->setGeometry(QRect(10, 120, 271, 24));
        CodigoSalida = new QLineEdit(tab_3);
        CodigoSalida->setObjectName(QString::fromUtf8("CodigoSalida"));
        CodigoSalida->setGeometry(QRect(300, 50, 51, 24));
        CantidadSalida = new QSpinBox(tab_3);
        CantidadSalida->setObjectName(QString::fromUtf8("CantidadSalida"));
        CantidadSalida->setGeometry(QRect(300, 120, 46, 25));
        CantidadSalida->setMinimum(1);
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(300, 100, 111, 16));
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 90, 271, 16));
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(300, 20, 271, 16));
        ResponsableSalida = new QLineEdit(tab_3);
        ResponsableSalida->setObjectName(QString::fromUtf8("ResponsableSalida"));
        ResponsableSalida->setGeometry(QRect(10, 50, 271, 24));
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 20, 271, 16));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 70, 80, 25));
        TabIngresar->addTab(tab_3, QString());
        TabMostrar = new QTabWidget(centralwidget);
        TabMostrar->setObjectName(QString::fromUtf8("TabMostrar"));
        TabMostrar->setGeometry(QRect(20, 230, 1221, 481));
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 6, 171, 20));
        TableInventario = new QTableWidget(widget);
        TableInventario->setObjectName(QString::fromUtf8("TableInventario"));
        TableInventario->setGeometry(QRect(10, 30, 1171, 391));
        TabMostrar->addTab(widget, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        TablesEntradas = new QTableWidget(tab_5);
        TablesEntradas->setObjectName(QString::fromUtf8("TablesEntradas"));
        TablesEntradas->setGeometry(QRect(10, 30, 1171, 391));
        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 6, 171, 20));
        TabMostrar->addTab(tab_5, QString());
        cframe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cframe);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1297, 25));
        menuCopeco = new QMenu(menubar);
        menuCopeco->setObjectName(QString::fromUtf8("menuCopeco"));
        cframe->setMenuBar(menubar);
        statusbar = new QStatusBar(cframe);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        cframe->setStatusBar(statusbar);

        menubar->addAction(menuCopeco->menuAction());

        retranslateUi(cframe);

        TabIngresar->setCurrentIndex(0);
        TabMostrar->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(cframe);
    } // setupUi

    void retranslateUi(QMainWindow *cframe)
    {
        cframe->setWindowTitle(QApplication::translate("cframe", "cframe", nullptr));
        label_3->setText(QApplication::translate("cframe", "Ingrese su usuario", nullptr));
        botonlogearse->setText(QApplication::translate("cframe", "Ingresar", nullptr));
        label_4->setText(QApplication::translate("cframe", "Ingrese su contrase\303\261a", nullptr));
        TabIngresar->setTabText(TabIngresar->indexOf(tab), QApplication::translate("cframe", "Login", nullptr));
        label_5->setText(QApplication::translate("cframe", "Nombre producto", nullptr));
        label_6->setText(QApplication::translate("cframe", "Procedencia", nullptr));
        label_7->setText(QApplication::translate("cframe", "Nombre del Responsable", nullptr));
        label_8->setText(QApplication::translate("cframe", "Recibe conforme", nullptr));
        label_9->setText(QApplication::translate("cframe", "Codigo", nullptr));
        label_10->setText(QApplication::translate("cframe", "Cantidad", nullptr));
        pushButton->setText(QApplication::translate("cframe", "Registrar", nullptr));
        TabIngresar->setTabText(TabIngresar->indexOf(tab_2), QApplication::translate("cframe", "Entrada", nullptr));
        label_19->setText(QApplication::translate("cframe", "Cantidad a retirar", nullptr));
        label_20->setText(QApplication::translate("cframe", "Entregado a", nullptr));
        label_21->setText(QApplication::translate("cframe", "Codigo del producto", nullptr));
        label_22->setText(QApplication::translate("cframe", "Responsable de bodega", nullptr));
        pushButton_3->setText(QApplication::translate("cframe", "Registrar", nullptr));
        TabIngresar->setTabText(TabIngresar->indexOf(tab_3), QApplication::translate("cframe", "Salida", nullptr));
        label_2->setText(QApplication::translate("cframe", "Inventario", nullptr));
        TabMostrar->setTabText(TabMostrar->indexOf(widget), QApplication::translate("cframe", "Inventario", nullptr));
        label->setText(QApplication::translate("cframe", "Entradas/Salidas", nullptr));
        TabMostrar->setTabText(TabMostrar->indexOf(tab_5), QApplication::translate("cframe", "Entradas/Salidas", nullptr));
        menuCopeco->setTitle(QApplication::translate("cframe", "Copeco", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cframe: public Ui_cframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFRAME_H
