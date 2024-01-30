#include <iostream>
#include "list.h"

using namespace std;

void print_list(const List<int>& list) {
    cout << "The list contains " << list.size() << " values" << endl;
    cout << "The values in the list are: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << it->data << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter a list of values" << endl;
    List<int> list;
    int value;
    while (cin >> value) {
        list.push_back(value);
    }
    print_list(list);
    

    cout << endl << "Enter a value to search for: ";
    cin >> value;
    int index = list.find(value);
    if (index == -1) {
        cout << "The value " << value << " is not in the list" << endl;
    } else {
        cout << "The value " << value << " is at index " << index << endl;
    }

    cout << "Enter a value to insert: ";
    cin >> value;
    cout << "Enter an index to insert at: ";
    cin >> index;
    list.insert(value, index);
    print_list(list);

    cout << endl << "Enter an index to erase at: ";
    cin >> index;
    list.erase(index);
    print_list(list);
    
    cout << endl << "Enter a value to push front: ";
    cin >> value;
    list.push_front(value);
    print_list(list);

}