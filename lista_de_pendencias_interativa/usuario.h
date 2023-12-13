#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

using namespace std;

class Usuario
{
private:
    QString username;
    QString senha;
    int pontos;

public:
    Usuario();
    Usuario(QString username, QString senha, int pontos);
    QString getUsername();
    void setUsername(QString newUsername);
    QString getSenha();
    void setSenha(QString newSenha);
    int getPontos();
    void setPontos(int newPontos);
};

#endif // USUARIO_H
