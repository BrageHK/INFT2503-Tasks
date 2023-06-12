#include <iostream>

using namespace std;

int find_sum(const int *table, int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += *table++;
    }
    return sum;
}

int main() {
    // ------ OPPGAVE 1 --------
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
    cout << "p pointer value " << *p << " p address: " << p << endl;
    cout << "q pointer value: " << *q << " q address: " << q << endl;

    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cin >> text;
    cout << text;
    while (*pointer != search_for) {
        *pointer = search_for;
        pointer++;
    }

    // ------- OPPGAVE 4 --------
    int a = 5;
    int b; // Kan ikke definere minneadresse. Mulig å initialisere en variabel eller peker i stedet.
    int *c;
    c = &b;
    a = b + *c; // Skjønner ikke helt hva programmet vil her, men setter verdien av a til å være lik verdien av b og
    // verdien av c. Jeg regner med at man ikke har lyst til å sette minneadressen til en sum av de andre
    // minneadressene ettersom det kan lett føre til segmentation fault fordi minneadressen blir utenfor det programmet
    // har tilgang til.
    b = 2; // Er litt merkelig å prøve å sette minneadressen til 2. Setter heller vaiabelen til 2.


    // ------- OPPGAVE 5 -------
    cout << "\n----- Oppgave 5 -----" << endl;
    double number = 10.2;
    cout << "Number: " << number << endl;
    double *numPointer = &number;
    *numPointer = 3.3;
    cout << "Number: " << number << endl;
    double &referanse = number;
    referanse = 6.9;
    cout << "Number: " << number << endl << endl;

    // ----- OPPGAVE 6 ------
    cout << "----- Oppgave 6 -----" << endl;
    int table[20];
    for(int i = 0; i < 20; i++) {
        *(table+i) = i+1;
        cout << *(table+i) << " ";
    }
    cout << "\nSum: " << find_sum(table, 10) << endl;
    cout << "Sum: " << find_sum(table+10, 5) << endl;
    cout << "Sum: " << find_sum(table+15, 5) << endl;



    return 0;
}
