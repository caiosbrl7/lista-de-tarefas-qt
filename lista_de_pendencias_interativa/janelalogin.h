#ifndef JANELALOGIN_H
#define JANELALOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include "usuario.h"
#include "lista_tarefas.h"
#include "janelaprincipal.h"


QT_BEGIN_NAMESPACE
namespace Ui { class JanelaLogin; }
QT_END_NAMESPACE

class JanelaLogin : public QMainWindow
{
    Q_OBJECT

public:
    JanelaLogin(QWidget *parent = nullptr);
    ~JanelaLogin();

private slots:
    void on_login_clicked();
    void on_registrar_clicked();

private:
    Ui::JanelaLogin *ui;
};
#endif // JANELALOGIN_H
