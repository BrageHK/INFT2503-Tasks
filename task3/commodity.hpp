//
// Created by Brage Kvamme on 09/06/2023.
//

#ifndef TASK3_COMMODITY_HPP
#define TASK3_COMMODITY_HPP

#include <string>

using namespace std;



class Commodity {
private:
    string name;
    int id;
    double price;
    const double tax = 0.25;
public:
    Commodity(string name_, int id_, double price_);

    string get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(double quantity) const;
    void set_price(double price);
    double get_price_with_sales_tax(double quantity) const;
    double get_price_with_sales_tax() const;
};


#endif //TASK3_COMMODITY_HPP
