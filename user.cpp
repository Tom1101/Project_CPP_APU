//
// Created by Duc Tuan Anh NGUYEN on 02/04/2018.
//

#include "user.h"

string User::getPassword() {
    return this->password;
}

string User::getUsername() {
    return this->username;
}

void User::setPassword(string password) {
    this->password = password;
}

void User::setUsername(string username) {
    this->username = username;
}

void User::load_medicine() {
    ifstream data;
    data.open("data.txt");
    string name;
    string company;
    int batch;
    int price;
    string dom;
    string doe;
    int quantity;
    string line;
    while (getline(data, line)) {
        if (line != "newMedicine") continue;
        data >> batch >> name >> company >> price >> dom >> doe >> quantity;
        me = medicine(name, company, batch, price, dom, doe, quantity);
        list_me.addMedicine(me);
    }
};

void User::search_medicine() {
    int id;
    cout << "Enter The Batch Number Of Medicine:";
    cin >> id;
    if (id < list_me.getListMedicine().size()+1) {
        list_me.searchMedicine(id).view_medicine();
    } else {
        cout << "\nNot Find Batch Number Match with this Medicine ! \n";
    }
    cout << "\n" << endl;
};

void User::view_all_medicine() {
    for (int i = 0; i < list_me.getListMedicine().size(); i++) {
        list_me.getListMedicine().at(i).view_medicine();
    }
    cout << endl;
}

void User::menuAction() {
}
void User::login(){
}

int User::showMenu() {
    int op;
    cout << "Welcome !" << endl;
    cout << "\t1. Customer" <<endl;
    cout << "\t2. Admin" <<endl;
    cout << "\t3. Exit" <<endl;
    cout << "-----------------" << endl;
    cout <<"Enter your option: ";
    cin >> op;
    return op;
};

void User::clear() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
        system("cls");
#endif
    }



