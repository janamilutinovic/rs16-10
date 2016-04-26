#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>

namespace Ui {
class quiz;
}

class quiz : public QWidget
{
    Q_OBJECT

public:
    explicit quiz(QWidget *parent = 0);
    ~quiz();

private slots:
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_quiz_destroyed();
    void kraj();

private:
    Ui::quiz *ui;
    void readFile(QString fileName);
    QString correct_answer;
};

#endif // QUIZ_H
