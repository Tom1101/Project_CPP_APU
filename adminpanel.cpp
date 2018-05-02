//
// Created by Duc Tuan Anh NGUYEN on 02/04/2018.
//
#include "adminpanel.h"

    void Admin::login() {
        setUsername("admin");
        setPassword("admin");
        cout << "Username: ";
        cin.ignore();
        getline(cin, login_user);
        cout << "Password: ";
        getline(cin, login_pass);
        if (login_user == getUsername()) {
            if (login_pass == getPassword()) {
                menuAction();
            } else {
                cout << "\nWrong Password" << endl;
            }
        } else {
            cout << "\nWrong Username" << endl;
        };
    }

    void Admin::menuAction() {
        load_medicine();
        int op;
        do {
            op = showMenu();
            switch (op) {
                case 1:
                    clear();
                    add_medicine();
                    break;
                case 2:
                    clear();
                    modify_medicine();
                    break;
                case 3:
                    clear();
                    delete_medicine();
                    break;
                case 4:
                    clear();
                    search_medicine();
                    break;
                case 5:
                    clear();
                    view_all_medicine();
                    cout << "\n";
                    break;
                case 6:
                    clear();
                    search_date_expiry();
                    cout << "\n";
                    break;
                default:break;
            }
        } while (op != 7);
    };

    int Admin::showMenu() {
        int op;
        cout << "1. Add Medicine" << endl;
        cout << "2. Update Medicine" << endl;
        cout << "3. Delete Medicine" << endl;
        cout << "4. Search Medicine by Batch Number" << endl;
        cout << "5. View all Medicine" << endl;
        cout << "6. Find expiry date" << endl;
        cout << "7. Exit" << endl;
        cout << "------------------" << endl;
        cout << "Enter your option: ";
        cin >> op;
        return op;
    };

    void Admin::add_medicine() {
        char ch;
        int batch;
        do {
            cout << "\nEnter Batch Number of Medicine: " << endl;
            cin >> batch;
            try{
                list_me.ifExits(batch);
                me.setBatch(batch);
                me.create_medicine();
                ofstream data;
                data.open("data.txt", ios_base::out | ios_base::app);
                data << me.toString() << endl;
                cout << "\n\nDo you want to add more record..(y/n?)";
                cin >> ch;
                data.close();
                list_me.resetList();
                load_medicine();
            } catch ( CANT_FIND_MEDICINE_EXCEPTION e) {
                cout << e.what();
            }
        } while (ch == 'y' || ch == 'Y');
    };

    void Admin::delete_medicine() {
        char de;
        int id,quantity;
        cout << "\n\nEnter Batch Number of Medicine for delete: ";
        cin >> id;
        try {
            list_me.ifExits(id);
            cout << "\nMedicine has found ! \n";
            me = list_me.searchMedicine(id);
            cout << "This medicine has: " << me.getQuantity() << " quantities \n";
            cout << "How many quantity you want to delete from this medicine: ";
            cin >> quantity;
            if(quantity == me.getQuantity()){
                cout << "\n\nAre you sure to delete all " << me.getQuantity() << " quantites? (y/n) \n";
                cin >> de;
                if (de == 'y' || de == 'Y') {
                    list_me.deleteMedicine(me);
                    ofstream data;
                    data.open("data.txt",ios::trunc | ios::out);
                    data << list_me.toString() << endl;
                    cout << "\nDelete All Successful" << endl;
                    data.close();
                } else {
                    cout << "\nOk back to menu ! \n";
                }
            } else if (quantity < me.getQuantity()) {
                cout << "\n\nAre you sure to delete " << quantity << " quantities? (y/n)\n";
                cin >> de;
                if (de == 'y' || de == 'Y') {
                    list_me.modifyQuantity(me,quantity);
                    ofstream data;
                    data.open("data.txt",ios::trunc | ios::out);
                    data << list_me.toString() << endl;
                    cout << "\nDelete Successful" << endl;
                    cout << "\nDelete " << quantity <<" Quantites Successful" << endl;
                    data.close();
                } else {
                    cout << "\nOk back to menu ! \n";
                }

            } else cout << "\n Number of quantity is not correct ! \n";
        } catch ( CANT_FIND_MEDICINE_EXCEPTION e) {
            cout << e.what();
        }
    };

    void Admin::modify_medicine(){
        char md;
        int id;
        cout << "\n\nEnter Batch Number of Medicine for modify: ";
        cin >> id;
        try{
            list_me.ifExits(id);
            cout << "\nMedicine has found ! \n";
            me = list_me.searchMedicine(id);
            cout << "\n\nAre you sure to modify..(y/n)? \n";
            cin >> md;
            if(md == 'y' || md == 'Y'){
                list_me.modifyMedicine(me);
                ofstream data;
                data.open("data.txt",ios::trunc | ios::out);
                data << list_me.toString() << endl;
                cout << "\nModified Successful" << endl;
                data.close();
            } else {
                cout << "\n Ok back to menu ! \n";
            }
        } catch ( CANT_FIND_MEDICINE_EXCEPTION e) {
            cout << e.what();
        }
    };

    void Admin::search_date_expiry(){
        int month_exp, year_exp;
        cout << "Enter Month (mm):";
        cin >> month_exp;
        cout << "Enter Year (yyyy):";
        cin >> year_exp;
        for ( int i = 0; i < list_me.searchDOE(month_exp,year_exp).size(); i++){
           list_me.searchDOE(month_exp,year_exp).at(i).view_medicine();
        };
        cout << endl;
        //cout << stoi(list_me.getListMedicine().at(3).getDoe().substr(6,4)) << " " << 2016 << endl;
    };
