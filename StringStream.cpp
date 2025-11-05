#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> result;
    stringstream ss(str);
    int num;
    char comma;

    while (ss >> num) {
        result.push_back(num);
        ss >> comma;
    }

    return result;
}

int main() {
    string input;
    cin >> input;

    vector<int> numbers = parseInts(input);
    for (int num : numbers) {
        cout << num << endl;
    }

    return 0;
}
