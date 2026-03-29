#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <math.h>

MainWindow::MainWindow (QWidget *parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
  ui->setupUi (this);
}

MainWindow::~MainWindow ()
{
  delete ui;
}


void MainWindow::on_pushButton_clicked()
{
  if (ui->lineEdit_1->text().isEmpty() || ui->lineEdit_2->text().isEmpty()) return;

  float number = ui->lineEdit_1->text().toFloat();
  float power = ui->lineEdit_2->text().toFloat();

  ui->label->setText(QString::number(pow(number, power)));
}

