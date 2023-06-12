#include <iostream>

using namespace std;

template <typename T>
bool equal(T a, T b) {
    cout << "Using generic template to check if " << a << " and " << b << " are equal" << endl;
    return a == b;
}
bool equal(double a, double b) {
    cout << "Using double template to check if " << a << " and " << b << " are equal" << endl;
    return abs(a - b) < 0.00001;
}

template <typename T, typename U>
class Pair {
    public:
        T first;
        U second;

        Pair(T first_, U second_) : first(first_), second(second_) {}

        Pair operator+(Pair &other) const {
            return Pair(first+other.first, second+other.second);
        }

        bool operator>(Pair &other) const {
            return first+second > other.second+other.first;
        }
    };

int main() {
    cout << equal(1, 1) << endl;
    cout << equal(1.33, 1.5-0.17) << endl;


    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;

    return 0;
}
