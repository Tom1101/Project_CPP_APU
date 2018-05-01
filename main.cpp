#include <iostream>
#include <string>
#include <fstream>
#include <curses.h>

using namespace std;

#include "adminpanel.h"
#include "customerpanel.h"

void takeUser(User *user){
    user->login();
}

int main() {
    User user;
    int op;
    do{
        op = user.showMenu();
        switch(op)
        {
            case 1:{
                User *customer1 = new Customer();
                takeUser(customer1);
            }
                break;
            case 2:{
                User *admin = new Admin();
                takeUser(admin);
            }
                break;
        }
    } while (op!=3);
    return 0;
}


