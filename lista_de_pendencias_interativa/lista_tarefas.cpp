#include "lista_tarefas.h"

Lista_tarefas::Lista_tarefas()
{

}

void Lista_tarefas::comprar(int pt)
{
    this->pontos -= pt;
}

int Lista_tarefas::getPontos()
{
    return this->pontos;
}

QString Lista_tarefas::getNome_usuario()
{
    return nome_usuario;
}

void Lista_tarefas::setPontos(int pt)
{
    this->pontos = pt;
}

void Lista_tarefas::setNome_usuario(QString name)
{
    nome_usuario = name;
}
