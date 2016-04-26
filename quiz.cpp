#include "quiz.h"
#include "ui_quiz.h"
#include <qfiledialog.h>
#include <qapplication.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <qinputdialog.h>
#include <qcolor.h>
#include<iostream>
#include <QDebug>
#include<QFile>
#include <QCloseEvent>


quiz::quiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::quiz)
{
    ui->setupUi(this);
    QString k=QString::number(qrand()%5);

    QString pwd("");
    char * PWD;
    PWD = getenv ("PWD");
    pwd.append(PWD);
    pwd.append("/quiz/pitanja/");

    QString fileN= QString(pwd+k+".txt");

    readFile(fileN);

}

quiz::~quiz()
{
    delete ui;
}


void quiz::readFile(QString fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Ucitavanje podataka o studentu", "Ne moze da se otvori datoteka", QMessageBox::Ok);
    }
    else
    {
        QString line;

        QTextStream t(&file);
        line=t.readLine();

        while(!line.endsWith("Odgovori:")) {
            ui->textEdit->append(line);
            ui->textEdit->setAlignment(Qt::AlignCenter);
            line=t.readLine();
        }
            line=t.readLine();
            ui->btn1->setText(line);

            line=t.readLine();
            ui->btn2->setText(line);

            line=t.readLine();
            ui->btn3->setText(line);

            line=t.readLine();
            ui->btn4->setText(line);

            correct_answer=t.readLine();
            //qDebug() << correct_answer;



        file.close();
    }
}

void quiz::on_btn1_clicked()
{
    if(ui->btn1->text()==correct_answer)
        ui->btn1->setStyleSheet("background-color: green");
    else
    {
        ui->btn1->setStyleSheet("background-color: red");
        kraj();
    }

}

void quiz::on_btn2_clicked()
{

    if(ui->btn2->text()==correct_answer)
        ui->btn2->setStyleSheet("background-color: green");
    else
    {
        ui->btn2->setStyleSheet("background-color: red");
        kraj();
    }
}

void quiz::on_btn3_clicked()
{

    if(ui->btn3->text()==correct_answer)
        ui->btn3->setStyleSheet("background-color: green");
    else
    {
        ui->btn3->setStyleSheet("background-color: red");
        kraj();
    }

}

void quiz::on_btn4_clicked()
{

   if(ui->btn4->text()==correct_answer)
        ui->btn4->setStyleSheet("background-color: green");
    else
    {
        ui->btn4->setStyleSheet("background-color: red");
        kraj();
    }
}


void quiz::on_quiz_destroyed()
{

}


void quiz::kraj() {
    if(ui->btn1->text()==correct_answer)
        ui->btn1->setStyleSheet("background-color: green");
    else if(ui->btn2->text()==correct_answer)
        ui->btn2->setStyleSheet("background-color: green");
    else if(ui->btn3->text()==correct_answer)
        ui->btn3->setStyleSheet("background-color: green");
    else
        ui->btn4->setStyleSheet("background-color: green");



}



