#ifndef CSVWRITTER_H
#define CSVWRITTER_H

#include <fstream>
#include <vector>

#include <employe.h>

class CSVWritter

{   std::fstream fout;

public:
    CSVWritter(const QString& filename);
    ~CSVWritter();
    bool is_open() const {return fout.is_open(); };

    void write(std::vector<Employe> em);
};

#endif // CSVWRITTER_H
