//
// Created by Duc Tuan Anh NGUYEN on 12/04/2018.
//

#ifndef PROJECT_APU_MEDICINE_H
#define PROJECT_APU_MEDICINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class medicine{
private:
    string name;
    string company;
    int batch;
    int price;
    string dom;
    string doe;
    int quantity;
public:
    medicine() {};
    ~medicine(){};
    medicine(string name, string company, int batch, int price, string dom, string doe, int quantity);
    void create_medicine();
    void view_medicine();
    void modify_medicine();
    int returneNO();
    int getQuantity();
    int getPrice();
    void setBatch(int batch);
    void setQuantity(int quantity);
    void updateQuantity(int quantity);
    void deleteQuantity(int quantity);
    string getDoe();
    string getName();
    string toString() const;
    void report();
};

#endif //PROJECT_APU_MEDICINE_H