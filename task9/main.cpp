#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    auto predicate = [](int i) { return i > 15; };
    auto pos = find_if(v1.begin(), v1.end(), predicate);
    (pos != end(v1))
        ? cout << "First number larger than 15: " << *pos << '\n'
        : cout << "v1 does not contain numbers that are larger than 15.\n";

    auto predicate2 = [](int i, int j){ return abs(i-j) <= 2; };
    auto pos2 = equal(v1.begin(), v1.begin()+5, v2.begin(), predicate2);
    cout << "Første 5 omtrent lik: ";
    cout << pos2 << endl;

    cout << "Første 4 omtrent lik: ";
    cout << equal(v1.begin(), v1.begin()+4, v2.begin(), predicate2) << endl;

    cout << "Erstatter oddetall med 100: ";
    vector<int> copy;
    copy.resize(v1.size());
    auto is_odd = [](int i){ return (i & 1)==1; };
    replace_copy_if(v1.begin(), v1.end(), copy.begin(), is_odd, 100);
    cout << copy << endl;

    return 0;
}
