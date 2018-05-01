//
// Created by Duc Tuan Anh NGUYEN on 16/04/2018.
//

#ifndef PROJECT_APU_CUSTOMERPANEL_H
#define PROJECT_APU_CUSTOMERPANEL_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "user.h"
#include "medicine-list.h"


class Customer : public User{
    medicine_list list_cart;
    string login_user, login_pass;
public:
    Customer() {};
    ~Customer() {};
    void login();
    void menuAction();
    int showMenu();
    void add_medicine_cart();
    void delete_medicine_cart();
    void check_medicine();
    void display_cart();
    void checkout();
};

#endif //PROJECT_APU_CUSTOMERPANEL_H
