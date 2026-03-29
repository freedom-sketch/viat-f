#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QIcon>

int main (int argc, char *argv[])
{
  QApplication a (argc, argv);

  MainWindow window;
  window.show();

  return QApplication::exec ();
}
