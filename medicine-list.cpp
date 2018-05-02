//
// Created by Duc Tuan Anh NGUYEN on 02/04/2018.
//
#include "medicine-list.h"

    void medicine_list::addMedicine(medicine me){
        list.push_back(me);
    };

    void medicine_list::deleteMedicine(medicine me){
        for( int i = 0; i < list.size(); i++){
            if(list.at(i).returneNO() == me.returneNO()) {
                list.erase(list.begin() + i);
            }
        }
    };

    void medicine_list::modifyQuantity(medicine me, int quantity){
        for( int i = 0; i < list.size(); i++){
            if(list.at(i).returneNO() == me.returneNO()){
                list.at(i).deleteQuantity(quantity);
            }
        }
    };

    void medicine_list::updateQuantity(medicine me, int quantity){
        for( int i = 0; i < list.size(); i++){
            if(list.at(i).returneNO() == me.returneNO()){
                list.at(i).updateQuantity(quantity);
            }
        }
    };

    void medicine_list::modifyMedicine(medicine me){
        for( int i = 0; i < list.size(); i++){
            if(list.at(i).returneNO() == me.returneNO()){
                list.at(i).modify_medicine();
            }
        }
    };

    void medicine_list::ifExits(int id){
        for( int i = 0; i < list.size(); i++){
            if( list.at(i).returneNO() == id){
                return;
            }
        }
        throw CANT_FIND_MEDICINE_EXCEPTION();
    }

    medicine medicine_list::searchMedicine(int id){
        medicine me;
        for( int i = 0; i < list.size(); i++){
            if(list.at(i).returneNO() == id) {
                me = list.at(i);
                return me;
            }
        }
        return me;
    };

    vector<medicine> medicine_list::searchDOE(int month,int year){
        vector<medicine> listExp;
        for(int i = 0; i < list.size(); i++){
            if(stoi(list.at(i).getDoe().substr(3,4)) < year){
                listExp.push_back(list.at(i));
            } else if (stoi(list.at(i).getDoe().substr(3,4)) == year && stoi(list.at(i).getDoe().substr(0,2)) < month){
                listExp.push_back(list.at(i));
            }
        }
        return listExp;
    };

    vector<medicine> medicine_list::getListMedicine(){
        return this->list;
    };

    string medicine_list::toString() {
        ostringstream res;
        for (int i = 0; i < list.size(); i++) {
            res << list.at(i).toString() <<"\n";
            cout << endl;
        }
        return res.str();
    };

    int medicine_list::sumPriceQuantity() {
        int res = 0;
        for(int i = 0; i < list.size(); i++){
            res += (list.at(i).getQuantity()*list.at(i).getPrice());
        }
        return res;
    }

    string medicine_list::listCheckout(){
        ostringstream res;
        for(int i = 0; i < list.size(); i++){
            res << "Batch number " << list.at(i).returneNO() << " : " << list.at(i).getName() << " : " << list.at(i).getQuantity() << " * " << list.at(i).getPrice() << " = " <<(list.at(i).getQuantity()*list.at(i).getPrice()) << " $" << endl;
            cout << endl;
        }
        return res.str();
    }

    void medicine_list::resetList() {
        this->list.clear();
    }
