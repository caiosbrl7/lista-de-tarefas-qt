#include "usuario.h"


Usuario::Usuario(QString username, QString senha, int pontos)
{
    this->username = username;
    this->senha = senha;
    this->pontos = pontos;
}

int Usuario::getPontos()
{
    return pontos;
}

void Usuario::setPontos(int newPontos)
{
    this->pontos = newPontos;
}

Usuario::Usuario(){
    this->username = "";
    this->senha = "";
}

QString Usuario::getUsername()
{
    return this->username;
}

void Usuario::setUsername(QString newUsername)
{
    this->username = newUsername;
}

QString Usuario::getSenha()
{
    return this->senha;
}

void Usuario::setSenha(QString newSenha)
{
    this->senha = newSenha;
}
