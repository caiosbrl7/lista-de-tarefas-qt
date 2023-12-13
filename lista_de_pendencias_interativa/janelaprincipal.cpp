#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"

Usuario usuario;

// Construtor da janela principal
JanelaPrincipal::JanelaPrincipal(QString user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);

    usuario.setUsername(user);

    QString local = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuario.getUsername() + "/";


    // Preenchendo o list widget com as tarefas salvas no arquivo do usuário
    QFile arquivo(local+"tarefas.txt");

    if(arquivo.open(QFile::ReadOnly|QFile::Text)){
        QTextStream saida(&arquivo);
        while(!saida.atEnd()){
            QListWidgetItem *item = new QListWidgetItem(saida.readLine());
            ui->listWidget->addItem(item);
            item->setCheckState(Qt::Unchecked);
        }
    }

    arquivo.close();

    // Preenchendo os labels que indicam o nome do usuário logado e a quantidade de pontos que ele possui baseado na quantidade de tarefas concluídas
    int contador = 0;

    QFile pontos(local+"pontos.txt");
    if(pontos.open(QFile::ReadOnly|QFile::Text)){
        QTextStream saida(&pontos);
        while(!saida.atEnd()){
            saida.readLine();
            contador++;
        }
    }

    pontos.close();

    usuario.setPontos(contador*20);

    ui->label_username2->setText("Usuário: " + user);
    ui->label_points2->setText("Pontos: " + QString:: number(usuario.getPontos()));

    // Adicionando o ícone de imagem
    ui->lbl_icone->setScaledContents(true);
    QPixmap pix("C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/icon.png");
    ui->lbl_icone->setPixmap(pix);

    // Determinando o nível do usuário de acordo com a quantidade de pontos
    if(usuario.getPontos() >= 0 and usuario.getPontos() <= 60){
        ui->status->setText("Iniciante");
    }else if(usuario.getPontos() > 60 and usuario.getPontos() <= 120){
        ui->status->setText("Explorador de Tarefas");
    }else if(usuario.getPontos() > 120 and usuario.getPontos() <= 200){
        ui->status->setText("Mestre das Listas");
    }else if(usuario.getPontos() > 200 and usuario.getPontos() <= 320){
        ui->status->setText("Trabalhador Incansável");
    }else if(usuario.getPontos() > 320 and usuario.getPontos() <= 480){
        ui->status->setText("Rei da Produtividade");
    }else if(usuario.getPontos() > 480){
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
    QString local = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuario.getUsername() + "/";

    int contador = 0;

    QFile pontos(local+"pontos.txt");
    if(pontos.open(QFile::ReadOnly|QFile::Text)){
        QTextStream saida(&pontos);
        while(!saida.atEnd()){
            saida.readLine();
            contador++;
        }
    }

    pontos.close();

    usuario.setPontos(contador*20);


    ui->label_points2->setText("Pontos: " + QString:: number(usuario.getPontos()));

}


void JanelaPrincipal::on_btn_add_clicked()
{
    //  Adiciona o item presente no lineEdit dentro da lista (não permite adicionar itens vazios)
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
    QString local = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuario.getUsername() + "/";

    // Marca a tarefa como concluída mudando a cor da fonte para verde e adiciona mais um registro no arquivo de tarefas concluídas
    if(ui->listWidget->count() > 0){
        ui->listWidget->currentItem()->setForeground(Qt::darkGreen);
        ui->listWidget->currentItem()->setCheckState(Qt::Checked);
        QMessageBox::information(this, "Parabéns", "Tarefa concluída! +20 Pontos");

            QFile pontos(local+"pontos.txt");
            if(pontos.open(QFile::WriteOnly|QFile::Text|QFile::Append)){
                QTextStream entrada(&pontos);
                entrada << "Tarefa concluída! +20 pontos!" << "\n";
                pontos.flush();
            }

            pontos.close();
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
    QString local = "C:/Users/Caio/Desktop/sistema-gerenciamento-tarefas/registros/" + usuario.getUsername() + "/";

    if (QMessageBox::question(this, "Salvar tarefas", "Deseja salvar suas tarefas?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        QFile arquivo(local+"tarefas.txt");

        if(arquivo.open(QFile::WriteOnly|QFile::Text)){
            QTextStream entrada(&arquivo);
            for(int i = 0; i < ui->listWidget->count(); ++i){
                if(ui->listWidget->item(i)->checkState() == Qt::Unchecked){
                QString in = ui->listWidget->item(i)->text() + "\n";
                entrada << in;
                }
            }
            arquivo.flush();
        }

        arquivo.close();

        QMessageBox::information(this, "Salvo", "Tarefas Salvas! Ao fechar o programa, suas tarefas continuarão aqui.");
    }

}
