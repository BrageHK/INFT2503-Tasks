#include <iostream>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;
    cout << "\ni: Value: " << i << " Address: " << &i << endl;
    cout << "\nj: Value: " << j << " Address: " << &j << endl;
    cout << "\np: Address: " << p << " Value: " << *p << endl;
    cout << "\nq: Address: " << q << " Value: " << *q << endl << endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << "p pointer: " << *p << " p value: " << p << endl;
    cout << "q pointer: " << *q << " q value: " << q << endl;

    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cin >> text;
    cout << text;
    while (*pointer != search_for) {
        *pointer = search_for;
        pointer++;
    }
    return 0;
}
