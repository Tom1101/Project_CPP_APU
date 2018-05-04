//
// Created by Duc Tuan Anh NGUYEN on 15/04/2018.
//

#ifndef PROJECT_APU_MEDICINE_LIST_H
#define PROJECT_APU_MEDICINE_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


#include "medicine.h"
#include "exception.h"

using namespace std;

class medicine_list
{
public:
    medicine_list(){};
    ~medicine_list(){};
    void addMedicine(medicine me);
    void deleteMedicine(medicine me);
    void modifyQuantity(medicine me, int quantity);
    void updateQuantity(medicine me, int quantity);
    void modifyMedicine(medicine me);
    int sumPriceQuantity();
    void ifExits(int id);
    medicine searchMedicine(int id);
    vector<medicine> searchDOE(int month,int year);
    vector<medicine> getListMedicine();
    string toString();
    string listCheckout();
    void resetList();
private:
    vector<medicine> list;
};



#endif //PROJECT_APU_MEDICINE_LIST_H