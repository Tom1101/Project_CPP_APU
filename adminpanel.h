//
// Created by Duc Tuan Anh NGUYEN on 15/04/2018.
//

#ifndef PROJECT_APU_ADMINPANEL_H
#define PROJECT_APU_ADMINPANEL_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "medicine-list.h"
#include "user.h"

class Admin : public User {
private:
    string login_user, login_pass;
public:
    Admin() {};
    ~Admin() {};
    void login();
    void menuAction();
    int showMenu();
    void add_medicine();
    void delete_medicine();
    void modify_medicine();
    void search_date_expiry();
};

#endif //PROJECT_APU_ADMINPANEL_H