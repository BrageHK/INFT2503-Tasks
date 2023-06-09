#include "commodity.hpp"
#include <iostream>

using namespace std;

const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);
    double get_area() const;
    double get_circumference() const;
private:
    double radius;
};

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {}

double Circle::get_area() const {
    return pi * radius * radius;
}

double Circle::get_circumference() const {
    double circumference = 2.0 * pi * radius;
    return circumference;
}

using namespace std;

int main() {
    cout << "Oppgave 1 og 2:\n\n";

    Circle circle(5);

    double area = circle.get_area();
    cout << "Arealet er lik " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl << endl;


    cout << "Oppgave 3:\n\n";

    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id() << " Pris pr enhet: " << commodity.get_price() << endl;

    cout << "Kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    commodity.set_price(79.60);
    cout << "Ny kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    cout << "Oppgave 4:\n\n";
    string word1, word2, word3;
    cout << "Første ord: ";
    cin >> word1;
    cout << "Andre ord: ";
    cin >> word2;
    cout << "Tredje ord: ";
    cin >> word3;
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << endl << sentence << endl;
    cout << "Ord 1 lengde: " << word1.length() << endl;
    cout << "Ord 2 lengde: " << word2.length() << endl;
    cout << "Ord 3 lengde: " << word3.length() << endl;
    cout << "Setning: " << sentence << endl;
    cout << "Lengde på setning: " << sentence.length() << endl;
    string sentence2 = sentence;
    for(int i = 9; i < 12; i++) {
        if(sentence2.length() > i)
            sentence2[i] = 'x';
        else
            break;
    }
    cout << "Setning 2: " << sentence2 << endl;
    string sentence_start = sentence.substr(0, 5);
    cout << "Starten av setning: " << sentence_start << endl;
    if(sentence_start.contains("hallo"))
        cout << "Setningen inneholder \"hallo\"" << endl;
    else
        cout << "Setningen inneholder ikke \"hallo\"" << endl;

    string searchStr = "er";
    size_t pos = sentence.find(searchStr);

    while (pos != string::npos) {
        cout << "Funn på indeks: " << pos << endl;
        pos = sentence.find(searchStr, pos + 1);
    }

}

/* Utskrift:
Varenavn: Norvegia, varenr: 123 Pris pr enhet: 73.5
Kilopris: 73.5
Prisen for 2.5 kg er 183.75 uten moms
Prisen for 2.5 kg er 229.688 med moms
Ny kilopris: 79.6
Prisen for 2.5 kg er 199 uten moms
Prisen for 2.5 kg er 248.75 med moms
*/