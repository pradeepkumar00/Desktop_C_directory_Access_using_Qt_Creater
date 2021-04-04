#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QMessageBox>
QString g="C:/";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//ui->listWidget->addItem(item);
{
    ui->setupUi(this);
    //if(dir.exists()){
    //    QMessageBox::information(this,"My app","True");
    //}
    //else{
    //    QMessageBox::information(this,"My app","False");
    //}
    QString f="C:/";
    QDir dir(f);
    MainWindow::open_dir(dir);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open_dir(QDir S){
    //foreach (QFileInfo var,dir.drives()){
     ui->comboBox->addItem(S.absolutePath());
    foreach(QFileInfo var,S.entryInfoList()){
        if(var.isDir()){
            QString name = var.absoluteFilePath();
                ui->listWidget->addItem(name);
        }
        if(var.isFile()){
            QString name = var.fileName();
            ui->listWidget->addItem(name);
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
        g=ui->listWidget->currentItem()->text();
        QDir dir_2(g);
        if(dir_2.exists()){
            while(ui->listWidget->count()!=0){
                delete ui->listWidget->takeItem(ui->listWidget->count()-1);
            }
            MainWindow::open_dir(g);
        }
        else{
            QMessageBox::warning(this,"warning","This is not a directory");
        }
}
void MainWindow::on_pushButton_3_clicked()
{
    if(g=="C:/"){
        QMessageBox::warning(this,"Warning","You are already in home page");
    }else{
        g="C:/";
         while(ui->listWidget->count()!=0){
             delete ui->listWidget->takeItem(ui->listWidget->count()-1);
         }
         MainWindow::open_dir(g);
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    if(g=="C:/"){
        QMessageBox::warning(this,"Warning","You are already in home page");
    }else{
        QString d=g+"/../";
        QDir dir(d);
        g=dir.absolutePath();
        while(ui->listWidget->count()!=0){
            delete ui->listWidget->takeItem(ui->listWidget->count()-1);
        }
        MainWindow::open_dir(dir);
    }
}
void MainWindow::on_pushButton_1_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString p=ui->lineEdit->text();
    g=g+"/"+p;
    QDir dir(g);
    if(dir.exists()){
        QMessageBox::warning(this,"Warning","Please change directory name. Same name directory already here");
    }
    else{
        dir.mkpath(g);
        QMessageBox::about(this,"Success","Folder name "+p+" is created successfuly");
    }
}
