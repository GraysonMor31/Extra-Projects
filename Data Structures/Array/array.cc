#include "array.h"
#include <string>
#include <iostream>

using namespace std;

void print_array(Array<int>& a) {
    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

int sum_array(Array<int>& a) {
    int sum = 0;
    for (auto i = a.begin(); i != a.end(); ++i) {
        sum += *i;
    }
    return sum;
}

int avg_array(Array<int>& a) {
    int avg = sum_array(a) / a.size();
    return avg;
}

int min_array(Array<int>& a) {
    int min = a.at(0);
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (*i < min) {
            min = *i;
        }
    }
    return min;
}

int max_array(Array<int>& a) {
    int max = a.at(0);
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (*i > max) {
            max = *i;
        }
    }
    return max;
}

string print_array_stats(Array<int>& a) {
    string stats = "Sum: " + std::to_string(sum_array(a)) + "\n";
    stats += "Average: " + std::to_string(avg_array(a)) + "\n";
    stats += "Min: " + std::to_string(min_array(a)) + "\n";
    stats += "Max: " + std::to_string(max_array(a)) + "\n";
    return stats;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    Array<int> a(size);

    cout << "Enter " << size << " elements of array: ";
    for (auto i = a.begin(); i != a.end(); ++i) {
        cin >> *i;
    }
    
    cout << "Array: ";
    print_array(a);
    cout << "Array stats: " << endl;
    print_array_stats(a);
    
    return 0;
}