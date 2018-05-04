//
// Created by Duc Tuan Anh NGUYEN on 01/04/2018.
//
#include "medicine.h"

medicine::medicine(string name, string company, int batch, int price, string dom, string doe, int quantity) {
    this->name = name;
    this->company = company;
    this->batch = batch;
    this->price = price;
    this->dom = dom;
    this->doe = doe;
    this->quantity = quantity;
};

void medicine::create_medicine() {
    cout << "\nNew Medicine Entry...\n";
    cout << "\n\nMedicine No: " << this->batch;
    cout << "\nEnter The Name of Medicine: ";
    cin.ignore();
    getline(cin, name);
    cout << "\nEnter The Company of Medicine: ";
    getline(cin, company);
    cout << "\nEnter The Medicine Price: ";
    cin >> price;
    cin.ignore();
    while (true) {
        try {
            cout << "\nEnter Date of manufacture (mm-yyyy): ";
            getline(cin, dom);
            setDOM(getDOM());
            break;
        } catch (ERROR_DATE_EXCEPTION err) {
            cout << err.what();
        }
    }
    while (true) {
        try {
            cout << "\nEnter Date of expiry (mm-yyyy): ";
            getline(cin, doe);
            setDOE(getDoe(), getDOM());
            break;
        } catch (ERROR_DATE_EXCEPTION err) {
            cout << err.what();
        }
    }
    cout << "\nEnter Quantity: ";
    cin >> quantity;
    cout << "\n\nMedicine added...\n";
}

void medicine::view_medicine() {
    cout << "\n\nMedicine No: " << this->batch;
    cout << "\nMedicine Name: " << this->name;
    cout << "\nMedicine Company: " << this->company;
    cout << "\nMedicine Price: " << price << " RM";
    cout << "\nMedicine Date of Manufacture: " << dom;
    cout << "\nMedicine Date of Expiry: " << doe;
    cout << "\nMedicine Quantity: " << quantity;
}

void medicine::modify_medicine() {
    cout << "\n\nNew Medicine Entry...\n";
    cout << "\nEnter The Medicine No: " << batch;
    cout << "\nEnter The Name of Medicine: ";
    cin.ignore();
    getline(cin, name);
    cout << "\nEnter The Company of Medicine: ";
    getline(cin, company);
    cout << "\nEnter The Medicine Price: ";
    cin >> price;
    cin.ignore();
    while (true) {
        try {
            cout << "\nEnter Date of manufacture (mm-yyyy): ";
            getline(cin, dom);
            setDOM(getDOM());
            break;
        } catch (ERROR_DATE_EXCEPTION err) {
            cout << err.what();
        }
    }
    while (true) {
        try {
            cout << "\nEnter Date of expiry (mm-yyyy): ";
            getline(cin, doe);
            setDOE(getDoe(), getDOM());
            break;
        } catch (ERROR_DATE_EXCEPTION err) {
            cout << err.what();
        }
    }
    cout << "\nEnter Quantity: ";
    cin >> quantity;
    cout << "\n\nMedicine modified...";
}

int medicine::returneNO() {
    return batch;
}

int medicine::getQuantity() {
    return this->quantity;
}

int medicine::getPrice() {
    return this->price;
}

string medicine::getName() {
    return this->name;
}

void medicine::deleteQuantity(int quantity) {
    this->quantity -= quantity;
}

void medicine::setQuantity(int quantity) {
    this->quantity = quantity;
}

void medicine::updateQuantity(int quantity) {
    this->quantity += quantity;
}

void medicine::setBatch(int batch) {
    this->batch = batch;
}

void medicine::setDOE(string doe, string dom) {
    try {
        if ((doe.size() != 7) || (stoi(doe.substr(0, 2)) >= 12) || (doe.substr(2, 1) != "-")) {
            throw ERROR_DATE_EXCEPTION();
        } else if (stoi(dom.substr(3, 4)) > stoi(doe.substr(3, 4))) {
            throw ERROR_DATE_EXCEPTION();
        } else if (stoi(dom.substr(3, 4)) == stoi(doe.substr(3, 4)) &&
                   stoi(dom.substr(0, 2)) >= stoi(doe.substr(0, 2))) {
            throw ERROR_DATE_EXCEPTION();
        } else {
            this->doe = doe;
        }
    } catch (invalid_argument arg) {
        arg.what();
    }
}

void medicine::setDOM(string dom) {
    try {
        if ((dom.size() != 7) || (stoi(dom.substr(0, 2)) >= 12) || (dom.substr(2, 1) != "-")) {
            throw ERROR_DATE_EXCEPTION();
        } else {
            this->dom = dom;
        }
    } catch (invalid_argument arg) {
        arg.what();
    }
}

string medicine::getDoe() {
    return this->doe;
}

string medicine::getDOM() {
    return this->dom;
}

string medicine::toString() const {
    ostringstream res;
    res << "newMedicine\n" << batch << "\n" << name << "\n" << company << "\n" << price << "\n" << dom << "\n" << doe
        << "\n"
        << quantity << "\n";
    return res.str();
}
