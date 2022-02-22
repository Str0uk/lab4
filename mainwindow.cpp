#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <csvreader.h>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Открытие файла
    CSVReader csv("C:\\content\\OOP\\lab2\\lab2\\database.csv");
    if (csv.is_open()){
        //Чтение из файла в вектор
        auto employes = csv.readAll();
        std::cout << employes[0].id;
    }

    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SearchEmploye(){
    ui->textBrowser->append("Searching..");
    ui->textBrowser->append(QString::number(employes.size()));
    for (const auto &e: employes) {
//        if (e.full_name == ui->editSearch->text()){
            ui->textBrowser->append(e.full_name + ", " + QString::number(e.birth_year));
//        }
    }
}
