#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

const int MIN_W = 300;
const int MIN_H = 300;
const QString author_name = "Миша Боков";

int main(int argc, char *argv[])
{
    /* Объект приложения */
    QApplication app(argc, argv);

    /* Главный виджет, на него все крепим */
    QWidget widget;
    widget.setWindowTitle("Задание 1");
    widget.setMinimumSize(MIN_W, MIN_H);

    /* Вертикальный компановщик */
    QVBoxLayout *v_layout = new QVBoxLayout(&widget);

    /* Первый лейбл */
    QLabel *question_label = new QLabel("Догадайтесь, кто сделал этот проект?");
    /* Выравнивание лейбла по центре */
    question_label->setAlignment(Qt::AlignCenter);

    /* Первая кнопка */
    QPushButton *button = new QPushButton("Щелкните здесь!");

    /* Лейбл с именем автора проекта */
    QLabel *author_label = new QLabel(author_name);
    /* Выравнивание лейбла по центре */
    author_label->setAlignment(Qt::AlignCenter);
    author_label->hide();

    /* Добавление объектов в компановщик */
    v_layout->addWidget(question_label);
    v_layout->addWidget(author_label);
    v_layout->addWidget(button);

    /* Добавляем обработку сигнала нажатия кнопки */
    QObject::connect(button, &QPushButton::clicked, [button, author_label]() {
        /* Показываем лейбл, если он скрыть */
        if (author_label->isHidden()) {
            author_label->show();
            button->setText("Скрыть автора");
        }
        /* Скрываем, если открыт */
        else {
            author_label->hide();
            button->setText("Щелкните здвесь!");
        }
    });

    /* Отображаем основной виджет */
    widget.show();
    /* Запускаем приложение */
    return app.exec();
}