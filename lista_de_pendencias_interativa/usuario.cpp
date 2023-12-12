#include "usuario.h"


Usuario::Usuario(QString username, QString senha)
{
    this->username = username;
    this->senha = senha;
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
