//
// Created by Duc Tuan Anh NGUYEN on 02/05/2018.
//
#include <iostream>
using namespace std;

#ifndef PROJECT_APU_EXCEPTION_H
#define PROJECT_APU_EXCEPTION_H

class CANT_FIND_MEDICINE_EXCEPTION: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "\nCan't Find Batch Number Match with this Medicine ! \n";
    }
};

class ERROR_QUANTITIES_EXCEPTION: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "\nQuantity not valide ! Please Check Medicine for details\n";
    }
};

class ERROR_DATE_EXCEPTION: public exception{
public:
    virtual const char* what() const throw()
    {
        return "\nDate is invalid! Please Try Again\n";
    }
};
#endif //PROJECT_APU_EXCEPTION_H
