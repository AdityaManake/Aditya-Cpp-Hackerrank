#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    map<string, string> tagMap;
    vector<string> tagStack;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        ss >> word;

        if (word[1] == '/') {
            tagStack.pop_back();
        } else {
            string tagName = word.substr(1);
            if (tagName.back() == '>') tagName.pop_back();

            string fullPath = tagStack.empty() ? tagName : tagStack.back() + "." + tagName;
            tagStack.push_back(fullPath);

            string attrName, equalSign, attrValue;
            while (ss >> attrName >> equalSign >> attrValue) {
                if (attrValue.back() == '>') attrValue.pop_back();
                if (attrValue.front() == '"') attrValue = attrValue.substr(1);
                if (attrValue.back() == '"') attrValue.pop_back();
                tagMap[fullPath + "~" + attrName] = attrValue;
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        string query;
        getline(cin, query);
        auto it = tagMap.find(query);
        if (it != tagMap.end()) {
            cout << it->second << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
