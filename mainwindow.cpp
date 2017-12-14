#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "container.h"
#include "container.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   this->scene = new Container(this);
   ui->graphicsView->setScene(this->scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->scene->drawEdge(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toInt());
}
