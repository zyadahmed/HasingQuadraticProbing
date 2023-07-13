#include <iostream>
#include "hashT.h"
using namespace  std;
int main() {
    hashT<int> h(10);
    h.insert(10, 5);
    h.print();
    h.insert(15, 3);
    h.insert(20, 8);
    h.insert(25, 10);
    h.insert(10, 6);
    h.insert(30, 12);
    cout << "Hash table:" << endl;
    h.print();

    if (h.isFound(15)) {
        cout << "15 is found." << endl;
    } else {
        cout << "15 is not found." << endl;
    }

    if (h.isFound(35)) {
        cout << "35 is found." << endl;
    } else {
        cout << "35 is not found." << endl;
    }

    try {
        h.remove(25);
        h.remove(30);
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << "Hash table after removals:" << endl;
    h.print();

    return 0;
}