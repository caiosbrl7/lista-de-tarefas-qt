#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"

Usuario usuarioAtual;

// Construtor da janela principal
JanelaPrincipal::JanelaPrincipal(QString user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);

    usuarioAtual.setUsername(user);

    QString diretorioUsuario = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuarioAtual.getUsername() + "/";

    // Preenchendo o list widget com as tarefas salvas no arquivo do usuário
    QFile arquivoTarefas(diretorioUsuario + "tarefas.txt");

    if(arquivoTarefas.open(QFile::ReadOnly | QFile::Text)){
        QTextStream leitura(&arquivoTarefas);
        while (!leitura.atEnd()){
            QListWidgetItem *item = new QListWidgetItem(leitura.readLine());
            ui->listWidget->addItem(item);
            item->setCheckState(Qt::Unchecked);
        }
    }

    arquivoTarefas.close();

    // Preenchendo os labels que indicam o nome do usuário logado e a quantidade de pontos que ele possui baseado na quantidade de tarefas concluídas
    int contador = 0;

    QFile arquivoPontos(diretorioUsuario + "pontos.txt");
    if(arquivoPontos.open(QFile::ReadOnly | QFile::Text)){
        QTextStream leitura(&arquivoPontos);
        while (!leitura.atEnd()){
            leitura.readLine();
            contador++;
        }
    }

    arquivoPontos.close();

    usuarioAtual.setPontos(contador * 20);

    ui->label_username2->setText("Usuário: " + usuarioAtual.getUsername());
    ui->label_points2->setText("Pontos: " + QString::number(usuarioAtual.getPontos()));

    // Adicionando o ícone de imagem
    ui->lbl_icone->setScaledContents(true);
    QPixmap imagemIcone("C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/icon.png");
    ui->lbl_icone->setPixmap(imagemIcone);

    // Determinando o nível do usuário de acordo com a quantidade de pontos
    if(usuarioAtual.getPontos() >= 0 and usuarioAtual.getPontos() <= 60){
        ui->status->setText("Iniciante");
    }else if(usuarioAtual.getPontos() > 60 and usuarioAtual.getPontos() <= 120){
        ui->status->setText("Explorador de Tarefas");
    }else if(usuarioAtual.getPontos() > 120 and usuarioAtual.getPontos() <= 200){
        ui->status->setText("Mestre das Listas");
    }else if(usuarioAtual.getPontos() > 200 and usuarioAtual.getPontos() <= 320){
        ui->status->setText("Trabalhador Incansável");
    }else if(usuarioAtual.getPontos() > 320 and usuarioAtual.getPontos() <= 480){
        ui->status->setText("Rei da Produtividade");
    }else if(usuarioAtual.getPontos() > 480){
        ui->status->setText("Mago Supremo da Organização");
    }
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

// Função implementada para atualizar o label de pontos toda vez que uma tarefa for concluída
void JanelaPrincipal::atualizar_pontos()
{
    QString diretorioUsuario = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuarioAtual.getUsername() + "/";

    int contador = 0;

    QFile arquivoPontos(diretorioUsuario + "pontos.txt");
    if(arquivoPontos.open(QFile::ReadOnly | QFile::Text)){
        QTextStream saida(&arquivoPontos);
        while (!saida.atEnd()){
            saida.readLine();
            contador++;
        }
    }

    arquivoPontos.close();

    usuarioAtual.setPontos(contador * 20);

    ui->label_points2->setText("Pontos: " + QString::number(usuarioAtual.getPontos()));
}

void JanelaPrincipal::on_btn_add_clicked()
{
    // Adiciona o item presente no lineEdit dentro da lista (não permite adicionar itens vazios)
    QListWidgetItem *item = new QListWidgetItem(ui->lineEdit->text());
    if(!item->text().isEmpty()){
        ui->listWidget->addItem(item);
        item->setCheckState(Qt::Unchecked);
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
    }else{
        QMessageBox::warning(this, "Erro", "Linha vazia");
    }
}

void JanelaPrincipal::on_btn_concluida_clicked()
{
    QString diretorioUsuario = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuarioAtual.getUsername() + "/";

    // Marca a tarefa como concluída mudando a cor da fonte para verde e adiciona mais um registro no arquivo de tarefas concluídas
    if(ui->listWidget->count() > 0){
        ui->listWidget->currentItem()->setForeground(Qt::darkGreen);
        ui->listWidget->currentItem()->setCheckState(Qt::Checked);
        QMessageBox::information(this, "Parabéns", "Tarefa concluída! +20 Pontos");

            QFile arquivoPontos(diretorioUsuario + "pontos.txt");
            if(arquivoPontos.open(QFile::WriteOnly | QFile::Text | QFile::Append)){
                QTextStream entrada(&arquivoPontos);
                entrada << "Tarefa concluída! +20 pontos!" << "\n";
                arquivoPontos.flush();
            }

            arquivoPontos.close();
    }else{
        QMessageBox::warning(this, "Erro", "Lista de tarefas vazia");
    }

    // Atualização do label para mostrar a nova quantidade de pontos
    atualizar_pontos();
}

// Apaga a tarefa selecionada
void JanelaPrincipal::on_btn_remove_clicked()
{
    if (ui->listWidget->count() > 0){
        QListWidgetItem *item = ui->listWidget->currentItem();
        if (item) {
            ui->listWidget->takeItem(ui->listWidget->row(item));
            delete item;
        }
    }else{
        QMessageBox::warning(this, "Erro", "Lista de tarefas vazia");
    }
}

// Salva todas as tarefas no arquivo de tarefas do usuário
void JanelaPrincipal::on_btn_salvartarefas_clicked()
{
    QString diretorioUsuario = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuarioAtual.getUsername() + "/";

    if (QMessageBox::question(this, "Salvar tarefas", "Deseja salvar suas tarefas?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        QFile arquivoTarefas(diretorioUsuario + "tarefas.txt");

        if(arquivoTarefas.open(QFile::WriteOnly | QFile::Text)){
            QTextStream saida(&arquivoTarefas);
            for(int i = 0; i < ui->listWidget->count(); ++i){
                if(ui->listWidget->item(i)->checkState() == Qt::Unchecked){
                    QString linha = ui->listWidget->item(i)->text() + "\n";
                    saida << linha;
                }
            }
            arquivoTarefas.flush();
        }

        arquivoTarefas.close();

        QMessageBox::information(this, "Salvo", "Tarefas Salvas! Ao fechar o programa, suas tarefas continuarão aqui.");
    }
}
