#include "mainwindow.h"
#include "ui_mainwindow.h"

QString lineEdit_1;
QString lineEdit_2;

/* Конструктор класса главного окна MainWindow */
MainWindow::MainWindow (QWidget *parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
  ui->setupUi (this);
}

/* Деструктор класса главного окна MainWindow */
MainWindow::~MainWindow () {
  delete ui;
}

/* Начало описания слотов
Ниже представлены слоты-методы класса MainWindow */

/* Обработка изменения в полях для ввода текста (QLineEdit)
Просто записываем их значения в глобальные переменные */
void MainWindow::on_lineEdit_1_textChanged(const QString &arg1)
{
  lineEdit_1 = arg1;
}
void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
  lineEdit_2 = arg1;
}

/* Обработка нажатия кнопки (QPushButton) */
void MainWindow::on_pushButton_clicked()
{
  QString tmp = lineEdit_1;

  ui->lineEdit_1->setText(lineEdit_2);
  ui->lineEdit_2->setText(tmp);
}

