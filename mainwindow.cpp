#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybrowser.h"

#include <csvreader.h>
#include <csvwritter.h>
#include <iostream>
#include <QDebug>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Открытие файла
    CSVReader csv("C:\\content\\OOP\\lab2\\lab2\\database.csv");
    if (csv.is_open()){

        //Чтение из файла в вектор
        employes = csv.readAll();
    }

    // сортировка
        std::sort(employes.begin(), employes.end(), [](const Employe &c1, const Employe &c2){
            return c1.birth_year < c2.birth_year;;
        });

    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//Поиск по фамилии
void MainWindow::SearchEmploye(){
    ui->textBrowser->clear(); //Очищение браузера от продыдущих поисков.

    ui->textBrowser->GreenText("Searching..");
    //ui->textBrowser->append("Searching..");
    for (const auto &e: employes) {
        if (e.full_name == ui->editSearch->text()){
            ui->textBrowser->append("ID: " + QString::number(e.id) + ", " + e.full_name + ", " + QString::number(e.age()) + " years");
        }
    }
}

// Обработчик нажатия на кнопку ButtonAdd
void MainWindow::AddEmploye(){
    Employe em;
    em.id = ui->EditID->text().toInt();
    em.full_name = ui->EditName->text();
    em.birth_year = ui->EditYear->text().toInt();
    em.sex = static_cast<Sex>(ui->comboSex->currentIndex());


    employes.push_back(em);

    CSVWritter csv("C:\\content\\OOP\\lab2\\lab2\\updated_database.csv");

    csv.write(employes);

    ui->textBrowser->clear();
    ui->textBrowser->RedText("Person is added.");
    ui->EditID->clear();
    ui->EditName->clear();
    ui->EditYear->clear();

}
// добавлееие нового сотрудника в вектор
// Класс EmployeCSVWriter
