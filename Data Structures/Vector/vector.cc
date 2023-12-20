#include "vector.h"
#include <typeinfo>
#include <cmath>
#include <fstream>

using namespace std;

string printVector(const Vector<int>& v) {
    string s = "[";
    for (int i = 0; i < v.size(); i++) {
        s += to_string(v[i]);
        if (i != v.size() - 1) {
            s += ", ";
        }
    }
    s += "]";
    return s;
}

int vectorSum(const Vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

int vectorAverage(const Vector<int>& v) {
    return vectorSum(v) / v.size();
}

int vectorMedian(const Vector<int>& v) {
    Vector<int> copy = v;
    sort(copy.begin(), copy.end());
    return copy[copy.size() / 2];
}

int vectorMode(const Vector<int>& v) {
    Vector<int> copy = v;
    sort(copy.begin(), copy.end());
    int mode = copy[0];
    int mode_count = 1;
    int current = copy[0];
    int current_count = 1;
    for (int i = 1; i < copy.size(); i++) {
        if (copy[i] == current) {
            current_count++;
        }
        else {
            if (current_count > mode_count) {
                mode = current;
                mode_count = current_count;
            }
            current = copy[i];
            current_count = 1;
        }
    }
    if (current_count > mode_count) {
        mode = current;
        mode_count = current_count;
    }
    return mode;
}

int vectorMin(const Vector<int>& v) {
    int min = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

int vectorMax(const Vector<int>& v) {
    int max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

void printStats(const Vector<int>& v) {
    cout << "Vector: " << printVector(v) << endl;
    cout << "Sum: " << vectorSum(v) << endl;
    cout << "Average: " << vectorAverage(v) << endl;
    cout << "Median: " << vectorMedian(v) << endl;
    cout << "Mode: " << vectorMode(v) << endl;
    cout << "Min: " << vectorMin(v) << endl;
    cout << "Max: " << vectorMax(v) << endl;
}

void testVector() {
    ofstream logFile("vector_test_log.txt", ios::app);
    logFile << "Results of Tests on Vector Class:" << endl;
    Vector<int> v;

    // Test default constructor
    if (v.size() == 0 && v.capacity() == 0) {
        logFile << "Default constructor: PASS" << endl;
    }
    else {
        logFile << "Default constructor: FAIL" << endl;
    }

    // Test push_back
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if (v.size() == 3 && v.capacity() == 4) {
        logFile << "Push Back: PASS" << endl;
    }
    else {
        logFile << "Push Back: FAIL" << endl;
    }

    // Test copy constructor
    Vector<int> v2(v);
    if (v2.size() == 3 && v2.capacity() == 4) {
        logFile << "Copy constructor: PASS" << endl;
    }
    else {
        logFile << "Copy constructor: FAIL" << endl;
    }

    // Test move constructor
    Vector<int> v3(move(v));
    if (v3.size() == 3 && v3.capacity() == 4) {
        logFile << "Move constructor: PASS" << endl;
    }
    else {
        logFile << "Move constructor: FAIL" << endl;
    }

    // Test front
    if (v3.front() == 1) {
        logFile << "Front: PASS" << endl;
    }
    else {
        logFile << "Front: FAIL" << endl;
    }

    // Test back
    if (v3.back() == 3) {
        logFile << "Back: PASS" << endl;
    }
    else {
        logFile << "Back: FAIL" << endl;
    }

    // Test at
    if (v3.at(1) == 2) {
        logFile << "At: PASS" << endl;
    }
    else {
        logFile << "At: FAIL" << endl;
    }

    // Test operator[]
    if (v3[1] == 2) {
        logFile << "Operator[]: PASS" << endl;
    }
    else {
        logFile << "Operator[]: FAIL" << endl;
    }

    // Test pop_back
    v3.pop_back();
    if (v3.size() == 2 && v3.capacity() == 4) {
        logFile << "Pop Back: PASS" << endl;
    }
    else {
        logFile << "Pop Back: FAIL" << endl;
    }

    // Test clear
    v3.clear();
    if (v3.size() == 0 && v3.capacity() == 4) {
        logFile << "Clear: PASS" << endl;
    }
    else {
        logFile << "Clear: FAIL" << endl;
    }

    // Test resize
    v3.resize(10);
    if (v3.size() == 10 && v3.capacity() == 10) {
        logFile << "Resize: PASS" << endl;
    }
    else {
        logFile << "Resize: FAIL" << endl;
    }

    // Test reserve
    v3.reserve(20);
    if (v3.size() == 10 && v3.capacity() == 20) {
        logFile << "Reserve: PASS" << endl;
    }
    else {
        logFile << "Reserve: FAIL" << endl;
    }

    // Test shrink_to_fit
    v3.shrink_to_fit();
    if (v3.size() == 10 && v3.capacity() == 10) {
        logFile << "Shrink to Fit: PASS" << endl;
    }
    else {
        logFile << "Shrink to Fit: FAIL" << endl;
    }

    // Test iterator
    v3.begin();
    v3.end();
    if (v3.size() == 10 && v3.capacity() == 10) {
        logFile << "Iterator: PASS" << endl;
    }
    else {
        logFile << "Iterator: FAIL" << endl;
    }

    // Test Operators
    Vector<int> v4;
    v4.push_back(1);
    v4.push_back(2);
    v4.push_back(3);
    Vector<int> v5;
    v5.push_back(1);
    v5.push_back(2);
    v5.push_back(3);
    if (v4 == v5) {
        logFile << "Operator==: PASS" << endl;
    }
    else {
        logFile << "Operator==: FAIL" << endl;
    }

    v4.push_back(4);
    if (v4 != v5) {
        logFile << "Operator!=: PASS" << endl;
    }
    else {
        logFile << "Operator!=: FAIL" << endl;
    }

    if (v5 < v4) {
        logFile << "Operator<: PASS" << endl;
    }
    else {
        logFile << "Operator<: FAIL" << endl;
    }

    if (v5 <= v4) {
        logFile << "Operator<=: PASS" << endl;
    }
    else {
        logFile << "Operator<=: FAIL" << endl;
    }

    if (v4 > v5) {
        logFile << "Operator>: PASS" << endl;
    }
    else {
        logFile << "Operator>: FAIL" << endl;
    }

    if (v4 >= v5) {
        logFile << "Operator>=: PASS" << endl;
    }
    else {
        logFile << "Operator>=: FAIL" << endl;
    }

    v4.operator+=(v5);
    if (v4.size() == 7 && v4.capacity() == 10) {
        logFile << "Operator+=: PASS" << endl;
    }
    else {
        logFile << "Operator+=: FAIL" << endl;
    }

    v4.operator-=(1);
    if (v4.size() == 6 && v4.capacity() == 10) {
        logFile << "Operator-=: PASS" << endl;
    }
    else {
        logFile << "Operator-=: FAIL" << endl;
    }
}

template <typename T>
void userInput(Vector<T>& v) {
    cout << "Enter a list of numbers, separated by spaces: ";
    T input;
    while (cin >> input) {
        v.push_back(input);
    }
    if (typeid(T) == typeid(double)) {
        printStats(v);
    }
    else {
        cout << "Vector: " << printVector(v) << endl;
    }
}

int main() {
    Vector<int> v;
    userInput(v);
    return 0;
}