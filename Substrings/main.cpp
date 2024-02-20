#include <iostream>

using namespace std;

// Generate all substrings of a string
void substring(string s) {
    for (int i = 0; i < s.size(); i++) {
        string tmp;
        for (int j = i; j < s.size(); j++) {
            tmp += s[j];
            cout << tmp << "  ";
        }
        cout << "\n";
    }

}

int main() {
    substring("123a");
    return 0;
}