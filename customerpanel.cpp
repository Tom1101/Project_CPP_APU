//
// Created by Duc Tuan Anh NGUYEN on 12/04/2018.
//
#include "customerpanel.h"

void Customer::login() {
    setUsername("customer");
    setPassword("customer");
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
    }
}

int Customer::showMenu() {
    int op;
    cout << "1. Check Medicine" << endl;
    cout << "2. View all Medicine" << endl;
    cout << "3. Search Medicine by Batch Number" << endl;
    cout << "4. Add Medicine to your cart" << endl;
    cout << "5. Delete Medicine from your cart" << endl;
    cout << "6. Display Cart & Bill" << endl;
    cout << "7. Exit" << endl;
    cout << "------------------" << endl;
    cout << "Enter your option: ";
    cin >> op;
    return op;
};

void Customer::menuAction() {
    load_medicine();
    int op;
    do {
        op = showMenu();
        switch (op) {
            case 1:
                clear();
                check_medicine();
                cout << "\n";
                break;
            case 2:
                clear();
                view_all_medicine();
                cout << "\n";
                break;
            case 3:
                clear();
                search_medicine();
                cout << "\n";
                break;
            case 4:
                clear();
                add_medicine_cart();
                break;
            case 5:
                clear();
                delete_medicine_cart();
                break;
            case 6:
                clear();
                checkout();
                break;
            default:
                break;
        }
    } while (op != 7);
}

void Customer::check_medicine() {
    int id;
    cout << "Enter The Batch Number Of Medicine:";
    cin >> id;
    if (id < list_me.getListMedicine().size() + 1) {
        if (list_me.searchMedicine(id).getQuantity() > 0) {
            cout << "\nThis Medicine is now available at " << list_me.searchMedicine(id).getQuantity() << " units"
                 << endl;
        } else {
            cout << "\n This Medicine is not available at this time";
        };
    } else {
        cout << "\nNot Find Batch Number Match with this Medicine ! \n";
    }
}

void Customer::add_medicine_cart() {
    int id, quantity;
    cout << "Enter The Batch Number of Medicine: ";
    cin >> id;
    if (id < list_me.getListMedicine().size() + 1) {
        if (list_cart.ifExits(id) != "exit") {
            cout << "How many unit of this Medicine: ";
            cin >> quantity;
            if (quantity <= list_me.searchMedicine(id).getQuantity()) {
                me = list_me.searchMedicine(id);
                me.setQuantity(quantity);
                list_cart.addMedicine(me);
                list_me.modifyQuantity(me,quantity);
                cout << "Added Successful ! Please check your cart" << endl;
            } else {
                cout << "\nQuantity not valide ! Please Check Medicine for details" << endl;
            }
            cout << endl;
        } else {
            cout << "How many unit of this Medicine: ";
            cin >> quantity;
            if (quantity <= list_me.searchMedicine(id).getQuantity()) {
                me = list_cart.searchMedicine(id);
                list_cart.updateQuantity(me, quantity);
                list_me.modifyQuantity(me,quantity);
                cout << "Update Successful ! Please check your cart" << endl;
            } else {
                cout << "\nQuantity not valide ! Please Check Medicine for details" << endl;
            }
            cout << endl;
        }
    } else {
        cout << "\nNot Find Batch Number Match with this Medicine ! \n";
    }

}

void Customer::delete_medicine_cart() {
    int id, quantity;
    cout << "Enter The Batch Number Of Medicine:";
    cin >> id;
    if (id < list_me.getListMedicine().size() + 1) {
        if (list_cart.ifExits(id) == "exit") {
            cout << "How many unit of this Medicine: ";
            cin >> quantity;
            if (quantity < list_cart.searchMedicine(id).getQuantity()) {
                me = list_cart.searchMedicine(id);
                list_cart.modifyQuantity(me, quantity);
                list_me.updateQuantity(me,quantity);
                cout << "Changed Successful ! Please check your cart" << endl;
            } else if (quantity == list_cart.searchMedicine(id).getQuantity()) {
                me = list_cart.searchMedicine(id);
                list_cart.deleteMedicine(me);
                list_me.updateQuantity(me,quantity);
                cout << "Deleted Successful ! Please check your cart" << endl;
            } else {
                cout << "\nQuantity not valide ! Please Check Medicine for details" << endl;
            }
            cout << endl;
        } else {
            cout << "\nNot Find Batch Number Match with this Medicine ! \n";
        }
    } else {
        cout << "\nNot Find Batch Number Match with this Medicine ! \n";
    }
}

void Customer::display_cart() {
    cout << "List of items :";
    for (int i = 0; i < list_cart.getListMedicine().size(); i++) {
        list_cart.getListMedicine().at(i).view_medicine();
    }
    cout << "\n" << endl;
}

void Customer::checkout() {
    string name;
    display_cart();
    cout << "If everything is ok, check the money !" << endl;
    cout << endl;
    cout << "Total by item : \n" << list_cart.listCheckout() << endl;
    cout << "Total : " << list_cart.sumPriceQuantity() << " $ " << endl;
    cout << endl;
}



