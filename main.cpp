#include "quiz.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    quiz w;
    w.show();
    return a.exec();
}
