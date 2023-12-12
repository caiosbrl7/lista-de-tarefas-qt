#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

using namespace std;

class Usuario
{
private:
    QString username;
    QString senha;

public:
    Usuario();
    Usuario(QString username, QString senha);
    QString getUsername();
    void setUsername(QString newUsername);
    QString getSenha();
    void setSenha(QString newSenha);
};

#endif // USUARIO_H
