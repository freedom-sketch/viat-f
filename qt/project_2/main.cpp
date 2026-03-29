#include "mainwindow.h"

#include <QLineEdit>
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  MainWindow window;
  window.show();

  return QApplication::exec();
}
