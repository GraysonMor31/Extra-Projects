#include <iostream>
#include "hashmap.h"

using namespace std;

int main() {
    cout << "Enter a set of key-value pairs, separated by spaces. "
         << "End with Ctrl-D.\n";
    HashMap<int, int> map;
    int key;
    int value;
    while (cin >> key >> value) {
        map.put(key, value);
    }
    cout << "Enter a key to look up its value: ";
    cin >> key;

    try {
        value = map.get(key);
        cout << "Value: " << value << endl;
    } catch (runtime_error &e) {
        cout << "Key not found" << endl;
    }

    cout << "Enter a key to remove: ";
    cin >> key;
    map.remove(key);
}