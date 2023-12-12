#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QDir>
#include "usuario.h"
#include "janelalogin.h"
#include "lista_tarefas.h"

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QString user, QWidget *parent = nullptr);
    ~JanelaPrincipal();
    void atualizar_pontos();

private slots:

    void on_btn_add_clicked();

    void on_btn_concluida_clicked();

    void on_btn_remove_clicked();

    void on_btn_salvartarefas_clicked();

private:
    Ui::JanelaPrincipal *ui;
    QString username;  
};

#endif // JANELAPRINCIPAL_H
