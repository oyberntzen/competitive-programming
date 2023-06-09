#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int compare(string left, string right) {
    //printf("%s | %s\n", left.c_str(), right.c_str());
    if (left[0] != '[' && right[0] != '[') {
        int left_num = stoi(left);
        int right_num = stoi(right);
        if (left_num < right_num) return 1;
        else if (left_num > right_num) return -1;
        return 0;
    }

    bool left_empty = false;
    if (left[0] == '[' && left.size() == 2) left_empty = true;
    bool right_empty = false;
    if (right[0] == '[' && right.size() == 2) right_empty = true;
    if (left_empty && !right_empty) return 1;
    if (!left_empty && right_empty) return -1;
    if (left_empty && right_empty) return 0;

    if (left[0] == '[') {
        left = left.substr(1, left.size()-2);
    }
    if (right[0] == '[') {
        right = right.substr(1, right.size()-2);
    }

    int n = 0;
    int left_elements = 1;
    for (int i = 0; i < left.size(); i++) {
        if (left[i] == '[') {
            n++;
        } else if (left[i] == ']') {
            n--;
        } else if (left[i] == ',' && n == 0) {
            left[i] = ' ';
            left_elements++;
        }
    }
    stringstream left_stream = stringstream(left);
    n = 0;
    int right_elements = 1;
    for (int i = 0; i < right.size(); i++) {
        if (right[i] == '[') {
            n++;
        } else if (right[i] == ']') {
            n--;
        } else if (right[i] == ',' && n == 0) {
            right[i] = ' ';
            right_elements++;
        }
    }
    stringstream right_stream = stringstream(right);

    //printf("%s / %s\n", left.c_str(), right.c_str());

    for (int i = 0; i < left_elements && i < right_elements; i++) {
        string left_element;
        left_stream >> left_element;

        string right_element;
        right_stream >> right_element;

        int result = compare(left_element, right_element);
        if (result != 0) return result;
    }

    if (left_elements < right_elements) return 1;
    if (left_elements > right_elements) return -1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    string l1, l2;
    int i = 1;
    int sum = 0;
    do {
        getline(cin, l1);
        getline(cin, l2);
        int result = compare(l1, l2);
        //printf("%d\n", result);
        if (result == 1) sum += i;

        i++;
    } while (getline(cin, l1));
    printf("%d\n", sum);
}