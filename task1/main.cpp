#include <fstream>
#include <iostream>
#include <string>

const int length = 5;

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    double temperatures[5];
    read_temperatures(temperatures, 5);

    for(int i = 0; i < length; i++) {
        cout << "Temperatur nr. " << i+1 << ": " << temperatures[i] << endl;
    }

    int under10 = 0;
    int between10and20 = 0;
    int over20 = 0;
    cout << "Du skal skrive inn 5 temperaturer." << endl;
    for(int i = 1; i < length+1; i++) {
        double temp;
        cout << "Temperatur nr. " << i << ": ";
        cin >> temp;
        if(temp < 10)
            under10++;
        else if(temp <= 20)
            between10and20++;
        else
            over20++;
    }
    cout << "Antall under 10 er " << under10 << endl;
    cout << "Antall mellom 10 og 20 er " << between10and20 << endl;
    cout << "Antall over 20 er " << over20 << endl;
    return 0;
}

void read_temperatures(double temperatures[], int length) {
    const char filename[] = "/Users/brage/Documents/cppForBroGrammers/task1/temperatur.txt";
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Feil ved åpning av utfil." << endl;
        exit(EXIT_FAILURE);
    }
    int number;
    int i = 0;
    while (file >> number || i > length) { // leser fram til filslutt
        temperatures[i++] = number;
    }
    file.close();
}