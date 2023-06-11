#pragma once

#include <vector>

class Mengde {
public:
    std::vector<int> tabell;

    Mengde();
    Mengde(int tall);
    Mengde(std::vector<int> tall);
    Mengde &operator+=(const Mengde &other); // union
    Mengde operator+(int tall) const; // add
    Mengde &operator++(); // print lol
    Mengde &operator=(const Mengde &other);
};