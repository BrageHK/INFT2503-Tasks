#include "Mengde.hpp"
#include <iostream>
#include <vector>


#include <utility>

using namespace std;

Mengde::Mengde() : tabell() {}

Mengde::Mengde(int tall) : tabell() {
    tabell.push_back(tall);
}

Mengde::Mengde(vector<int> tall) : tabell(std::move(tall)) {}

Mengde &Mengde::operator+=(const Mengde &other) {
    for (int i : other.tabell) {
        bool found = false;
        for (int j : tabell) {
            if (j == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            tabell.push_back(i);
        }
    }
    return *this;
}

Mengde &Mengde::operator++()  {
    cout << "{";
    for (int i = 0; i < tabell.size(); i++) {
        cout << tabell[i];
        if (i != tabell.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    return *this;
}

Mengde Mengde::operator+(int tall) const {
    cout << "Hello";
    vector<int> nyTabell = this->tabell;
    for(int i : nyTabell) {
        if (i == tall) {
            cout << i << " " << tall << endl;
            return {this->tabell};
        }
    }
    cout << "Hello2" << endl;
    nyTabell.push_back(tall);
    return Mengde(nyTabell);
}

Mengde &Mengde::operator=(const Mengde &other) {
    this->tabell = other.tabell;
    return *this;
}
