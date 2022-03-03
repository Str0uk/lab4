#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
enum Sex { MAN, WOMAN};

struct Employe
{
    int id;
    QString full_name;
    int birth_year;
    int age() const { return 2022 - birth_year; };
    Sex sex;

};

#endif // EMPLOYE_H
