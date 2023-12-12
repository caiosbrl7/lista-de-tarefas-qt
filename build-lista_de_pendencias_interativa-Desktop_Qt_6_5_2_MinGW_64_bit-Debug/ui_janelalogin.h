/********************************************************************************
** Form generated from reading UI file 'janelalogin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELALOGIN_H
#define UI_JANELALOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaLogin
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *username;
    QLineEdit *senha;
    QPushButton *login;
    QPushButton *registrar;
    QLabel *mensagem;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JanelaLogin)
    {
        if (JanelaLogin->objectName().isEmpty())
            JanelaLogin->setObjectName("JanelaLogin");
        JanelaLogin->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("accessories-calculator")));
        JanelaLogin->setWindowIcon(icon);
        centralwidget = new QWidget(JanelaLogin);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"\n"
"\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0.818, y1:0.16, x2:1, y2:1, stop:0.255682 rgba(0, 85, 255, 255), stop:1 rgba(0, 0, 147, 255));\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(210, 120, 350, 300));
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color:rgb(235, 235, 235);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        username = new QLineEdit(frame);
        username->setObjectName("username");
        username->setGeometry(QRect(30, 90, 291, 31));
        username->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color:white;\n"
"}"));
        senha = new QLineEdit(frame);
        senha->setObjectName("senha");
        senha->setGeometry(QRect(30, 150, 291, 31));
        senha->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color:white;\n"
"}"));
        senha->setEchoMode(QLineEdit::Password);
        login = new QPushButton(frame);
        login->setObjectName("login");
        login->setGeometry(QRect(20, 240, 141, 31));
        login->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:rgb(225, 225, 225);\n"
"}"));
        registrar = new QPushButton(frame);
        registrar->setObjectName("registrar");
        registrar->setGeometry(QRect(190, 240, 141, 31));
        registrar->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:rgb(225, 225, 225);\n"
"}"));
        mensagem = new QLabel(frame);
        mensagem->setObjectName("mensagem");
        mensagem->setGeometry(QRect(70, 30, 211, 31));
        QFont font;
        font.setBold(true);
        mensagem->setFont(font);
        JanelaLogin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JanelaLogin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        JanelaLogin->setMenuBar(menubar);
        statusbar = new QStatusBar(JanelaLogin);
        statusbar->setObjectName("statusbar");
        JanelaLogin->setStatusBar(statusbar);

        retranslateUi(JanelaLogin);

        QMetaObject::connectSlotsByName(JanelaLogin);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaLogin)
    {
        JanelaLogin->setWindowTitle(QCoreApplication::translate("JanelaLogin", "Login", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("JanelaLogin", "Username", nullptr));
        senha->setPlaceholderText(QCoreApplication::translate("JanelaLogin", "Senha", nullptr));
        login->setText(QCoreApplication::translate("JanelaLogin", "Login", nullptr));
        registrar->setText(QCoreApplication::translate("JanelaLogin", "Registrar", nullptr));
        mensagem->setText(QCoreApplication::translate("JanelaLogin", "Bem vindo! Fa\303\247a Login ou Registre-se.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaLogin: public Ui_JanelaLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELALOGIN_H
