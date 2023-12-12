#include "janelalogin.h"
#include "ui_janelalogin.h"

// Váriaveis responsaveis por indicar o local dos arquivos de usuarios e o nome padrão do arquivo de informações pessoais

QString local = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/";
QString nomearq = "credenciais.csv";

JanelaLogin::JanelaLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaLogin)
{
    ui->setupUi(this);
}

JanelaLogin::~JanelaLogin()
{
    delete ui;
}

void JanelaLogin::on_registrar_clicked()
{
    // Criando uma pasta para as informações do usuário com seu nome no local desejado -> 'local' (variável global)
    Usuario user(ui->username->text(), ui->senha->text());
    QString nome = user.getUsername();
    QDir pasta(local+nome);
    pasta.mkdir(local+nome);

    // QString que representa onde o arquivo de credenciais vai ser criado
    QString loc = local + user.getUsername() + "/";


    // Adicionando o arquivo de tarefas para o usuário
    QFile tarefas(loc+"tarefas.txt");
    if(tarefas.open(QFile::WriteOnly|QFile::Text)){
        tarefas.flush();
    }

    tarefas.close();

    QFile pontos(loc+"pontos.txt");
    if(pontos.open(QFile::WriteOnly|QFile::Text)){
        pontos.flush();
    }

    pontos.close();

    // Criando o arquivo e preenchendo com suas informações de login separadas por vírgula (padrão de arquivo .csv)
    // Após ser criado, fecha a aba e entra na janela principal
    QFile arquivo(loc+nomearq);
    if(arquivo.open(QFile::WriteOnly|QFile::Text|QFile::Append)){
        QTextStream saida(&arquivo);
        saida << user.getUsername() << "," << user.getSenha() << '\n';
        arquivo.flush();
        QMessageBox::information(this, "Seja bem vindo", "Usuario cadastrado com sucesso");
        this->hide();
        JanelaPrincipal *janela = new JanelaPrincipal(nome);
        janela->show();
    }else{
        QMessageBox::warning(this,"Erro", "Erro ao abrir ou encontrar o arquivo");
    }

    arquivo.close();
    ui->username->clear();
    ui->senha->clear();
}


void JanelaLogin::on_login_clicked()
{
    // Variável criada pra auxiliar na pesquisa das credenciais baseada no user inserido no line edit
    // Dependendo do usuário, o programa vai procurar em uma pasta especifica o arquivo que contém as credenciais de login
    Usuario user(ui->username->text(), ui->senha->text());
    QString loc = local + user.getUsername() + "/";
    QString nome = user.getUsername();

    // Pesquisa pelo arquivo de credenciais e usa o método .contains da biblioteca QString para verificar se o arquivo contem o conteudo
    // indicado (login e senha), se sim, retorna true
    QFile arquivo(loc+nomearq);
    if(arquivo.open(QFile::ReadOnly|QFile::Text)){
        QTextStream entrada(&arquivo);
        QString info = user.getUsername() + "," + user.getSenha();
        const QString conteudo = entrada.readAll();
        if(conteudo.contains(info)){
            QMessageBox::information(this, "Seja bem vindo", "Login realizado com sucesso");
            this->hide();
            JanelaPrincipal *janela = new JanelaPrincipal(nome);
            janela->show();
        }else{
            QMessageBox::warning(this,"Erro", "Usuario nao cadastrado");
        }
    }else{
      QMessageBox::warning(this,"Erro", "Usuario nao cadastrado");
    }
    arquivo.close();
    ui->username->clear();
    ui->senha->clear();
}



