#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>


struct Employe
{
    int id;
    QString full_name;
    int birth_year;
    int age() const { return 2022 - birth_year; };


};

#endif // EMPLOYE_H
