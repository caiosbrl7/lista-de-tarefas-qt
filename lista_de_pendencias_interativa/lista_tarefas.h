#ifndef LISTA_TAREFAS_H
#define LISTA_TAREFAS_H

#include <QString>

class Lista_tarefas
{
private:
    QString nome_usuario;
    int pontos;

public:
    Lista_tarefas();
    int getPontos();
    QString getNome_usuario();
    void setPontos(int pt);
    void setNome_usuario(QString name);
};

#endif // LISTA_TAREFAS_H
