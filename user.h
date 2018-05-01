//
// Created by Duc Tuan Anh NGUYEN on 16/04/2018.
//

#ifndef PROJECT_APU_USER_H
#define PROJECT_APU_USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdio>
#include "medicine-list.h"
using namespace std;

class User {
public:
    User() {};
    ~User() {};
    void setUsername(string username);
    void setPassword(string password);
    string getUsername();
    string getPassword();

    static void clear();

    virtual void login();
    virtual void menuAction();
    void load_medicine();
    void search_medicine();
    void view_all_medicine();
    virtual int showMenu();
protected:
    medicine me;
    medicine_list list_me;
    string username;
    string password;
};

#endif //PROJECT_APU_USER_H
