#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

int Convert(string s) {
    bool valid = true;
    if (s.empty())
        valid = false;
    for (char i : s)
        valid &= ((i <= '9') && (i >= '0'));
    if (!valid)
        assert (false);
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        x += ((int) s[i] - (int) '0') * pow(10, s.size() - 1 - i);
    }
    return x;
}

int main() {
    string s;
    cin >> s;
    cout << Convert(s);
    return 0;
}
