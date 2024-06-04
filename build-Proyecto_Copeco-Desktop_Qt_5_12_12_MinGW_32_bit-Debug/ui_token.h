/********************************************************************************
** Form generated from reading UI file 'token.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOKEN_H
#define UI_TOKEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Token
{
public:
    QLabel *lbl_TokenTitulo;
    QLabel *lbl_Token;
    QLabel *lbl_tiempo;

    void setupUi(QWidget *Token)
    {
        if (Token->objectName().isEmpty())
            Token->setObjectName(QString::fromUtf8("Token"));
        Token->resize(396, 252);
        lbl_TokenTitulo = new QLabel(Token);
        lbl_TokenTitulo->setObjectName(QString::fromUtf8("lbl_TokenTitulo"));
        lbl_TokenTitulo->setGeometry(QRect(0, 60, 391, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbl_TokenTitulo->setFont(font);
        lbl_TokenTitulo->setAlignment(Qt::AlignCenter);
        lbl_Token = new QLabel(Token);
        lbl_Token->setObjectName(QString::fromUtf8("lbl_Token"));
        lbl_Token->setGeometry(QRect(0, 100, 391, 51));
        QFont font1;
        font1.setPointSize(16);
        lbl_Token->setFont(font1);
        lbl_Token->setAlignment(Qt::AlignCenter);
        lbl_tiempo = new QLabel(Token);
        lbl_tiempo->setObjectName(QString::fromUtf8("lbl_tiempo"));
        lbl_tiempo->setGeometry(QRect(0, 150, 391, 20));
        QFont font2;
        font2.setPointSize(11);
        lbl_tiempo->setFont(font2);
        lbl_tiempo->setAlignment(Qt::AlignCenter);

        retranslateUi(Token);

        QMetaObject::connectSlotsByName(Token);
    } // setupUi

    void retranslateUi(QWidget *Token)
    {
        Token->setWindowTitle(QString());
        lbl_TokenTitulo->setText(QApplication::translate("Token", "Token", nullptr));
        lbl_Token->setText(QApplication::translate("Token", "-", nullptr));
        lbl_tiempo->setText(QApplication::translate("Token", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Token: public Ui_Token {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOKEN_H
