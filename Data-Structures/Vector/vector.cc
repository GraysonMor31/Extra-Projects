#include "vector.h"
#include <typeinfo>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

string print_vector_int(const Vector<int>& v) {
    string s = "[";
    for (int i = 0; i < v.size(); i++) {
        s += to_string(v.at(i));
        if (i != v.size() - 1) {
            s += ", ";
        }
    }
    s += "]";
    return s;
}

string print_vector_double(const Vector<double>& v) {
    string s = "[";
    for (int i = 0; i < v.size(); i++) {
        s += to_string(v.at(i));
        if (i != v.size() - 1) {
            s += ", ";
        }
    }
    s += "]";
    return s;
}

string print_vector_string(const Vector<string>& v) {
    string s = "[";
    for (int i = 0; i < v.size(); i++) {
        s += v.at(i);
        if (i != v.size() - 1) {
            s += ", ";
        }
    }
    s += "]";
    return s;
}

int sort_vector(Vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v.at(i) > v.at(j)) {
                int temp = v.at(i);
                v.at(i) = v.at(j);
                v.at(j) = temp;
            }
        }
    }
}

int sum_vector(const Vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v.at(i);
    }
}

int avg_vector(const Vector<int>& v) {
    return sum_vector(v) / v.size();
}

int median_vector(const Vector<int>& v) {
    Vector<int> v_copy = v;
    sort_vector(v_copy);
    if (v_copy.size() % 2 == 0) {
        return (v_copy.at(v_copy.size() / 2) + v_copy.at(v_copy.size() / 2 - 1)) / 2;
    }
    else {
        return v_copy.at(v_copy.size() / 2);
    }
}

int min_vector(const Vector<int>& v) {
    int min = v.at(0);
    for (int i = 1; i < v.size(); i++) {
        if (v.at(i) < min) {
            min = v.at(i);
        }
    }
    return min;
}

int max_vector(const Vector<int>& v) {
    int max = v.at(0);
    for (int i = 1; i < v.size(); i++) {
        if (v.at(i) > max) {
            max = v.at(i);
        }
    }
    return max;
}

string print_stats(const Vector<int>& v) {
    string stats = "The stats for this vector are:\n";
    stats += "Sum: " + to_string(sum_vector(v)) + "\n";
    stats += "Average: " + to_string(avg_vector(v)) + "\n";
    stats += "Median: " + to_string(median_vector(v)) + "\n";
    stats += "Min: " + to_string(min_vector(v)) + "\n";
    stats += "Max: " + to_string(max_vector(v)) + "\n";
    return stats;
}

int main() {
    Vector<int> v1;
    int input;
    cout << "Enter a list of integers, followed by a non-integer character: ";
    while (cin >> input && typeid(input) == typeid(int)) {
        v1.push_back(input);
    }
    cout << "The vector you entered is: " << print_vector_int(v1) << endl;
    cout << print_stats(v1) << endl;

    Vector<double> v2;
    double input2;
    cout << "Enter a list of doubles, followed by a non-double character: ";
    while (cin >> input2 && typeid(input2) == typeid(double)) {
        v2.push_back(input2);
    }

    Vector<string> v3;
    string input3;
    cout << "Enter a list of strings, followed by a non-string character: ";
    while (cin >> input3 && typeid(input3) == typeid(string)) {
        v3.push_back(input3);
    }
}