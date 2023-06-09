//
// Created by Brage Kvamme on 09/06/2023.
//

#include "commodity.hpp"
#include <string>

using namespace std;

Commodity::Commodity(string name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

string Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price(double quantity) const {
    return quantity * price;
}

void Commodity::set_price(double price) {
    this->price = price;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return get_price(quantity) * (tax+1);
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price_with_sales_tax() const {
    return price * (tax+1);
};

