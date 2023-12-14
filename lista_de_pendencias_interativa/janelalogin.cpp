#include "janelalogin.h"
#include "ui_janelalogin.h"

// Variáveis responsáveis por indicar o caminho dos arquivos de usuários e o nome padrão do arquivo de informações pessoais
QString caminhoArquivosUsuarios = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/";
QString nomeArquivoCredenciais = "credenciais.csv";

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
    // Criando uma pasta para as informações do usuário com seu nome no local desejado -> 'caminhoArquivosUsuarios' (variável global)
    Usuario usuario(ui->username->text(), ui->senha->text(), 0);
    QString nomeUsuario = usuario.getUsername();

    QFile arquivoCredenciais(caminhoArquivosUsuarios + nomeArquivoCredenciais);
    if(arquivoCredenciais.open(QFile::ReadOnly|QFile::Text)){
        QTextStream entradaDados(&arquivoCredenciais);
        QString infoUsuario = usuario.getUsername() + "," + usuario.getSenha();
        const QString conteudoArquivo = entradaDados.readAll();
        if(conteudoArquivo.contains(infoUsuario)){
            arquivoCredenciais.close();
            QMessageBox::warning(this, "Operação Inválida", "Usuário já registrado");
            ui->username->clear();
            ui->senha->clear();
            return;
        }
        arquivoCredenciais.close();
    }

    QDir pastaUsuario(caminhoArquivosUsuarios + nomeUsuario);
    pastaUsuario.mkdir(caminhoArquivosUsuarios + nomeUsuario);

    // QString que representa onde o arquivo de credenciais vai ser criado
    QString caminhoArquivoUsuario = caminhoArquivosUsuarios + usuario.getUsername() + "/";

    // Adicionando o arquivo de tarefas para o usuário
    QFile arquivoTarefas(caminhoArquivoUsuario + "tarefas.txt");
    if(arquivoTarefas.open(QFile::WriteOnly|QFile::Text)){
        arquivoTarefas.flush();
    }
    arquivoTarefas.close();

    QFile arquivoPontos(caminhoArquivoUsuario + "pontos.txt");
    if(arquivoPontos.open(QFile::WriteOnly|QFile::Text)){
        arquivoPontos.flush();
    }
    arquivoPontos.close();

    // Criando o arquivo e preenchendo com suas informações de login separadas por vírgula (padrão de arquivo .csv)
    // Após ser criado, fecha a aba e entra na janela principal
    QFile arquivo(caminhoArquivosUsuarios + nomeArquivoCredenciais);
    if(arquivo.open(QFile::WriteOnly|QFile::Text|QFile::Append)){
        QTextStream saida(&arquivo);
        saida << usuario.getUsername() << "," << usuario.getSenha() << '\n';
        arquivo.flush();
        QMessageBox::information(this, "Seja bem vindo", "Usuário cadastrado com sucesso");
        this->close();
        JanelaPrincipal *janela = new JanelaPrincipal(nomeUsuario);
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
    // Variável criada para auxiliar na pesquisa das credenciais baseada no usuário inserido no line edit
    // Dependendo do usuário, o programa vai procurar em uma pasta específica o arquivo que contém as credenciais de login
    Usuario usuario(ui->username->text(), ui->senha->text(), 0);
    QString nomeUsuario = usuario.getUsername();

    // Pesquisa pelo arquivo de credenciais e usa o método .contains da biblioteca QString para verificar se o arquivo contém o conteúdo
    // indicado (login e senha), se sim, retorna true
    QFile arquivo(caminhoArquivosUsuarios + nomeArquivoCredenciais);
    if(arquivo.open(QFile::ReadOnly|QFile::Text)){
        QTextStream entrada(&arquivo);
        QString info = usuario.getUsername() + "," + usuario.getSenha();
        const QString conteudo = entrada.readAll();
        if(conteudo.contains(info)){
            QMessageBox::information(this, "Seja bem vindo", "Login realizado com sucesso");
            this->hide();
            JanelaPrincipal *janela = new JanelaPrincipal(nomeUsuario);
            janela->show();
        }else{
            QMessageBox::warning(this,"Erro", "Usuário não cadastrado");
        }
    }else{
        QMessageBox::warning(this,"Erro", "Usuário não cadastrado");
    }
    arquivo.close();
    ui->username->clear();
    ui->senha->clear();
}
