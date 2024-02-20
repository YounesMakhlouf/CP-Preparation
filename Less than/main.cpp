#include <bits/stdc++.h>
#include <cassert>

using namespace std;


// Function to compare 2 strings. We also test it using random strings to verify it works.
bool compare(string a, string b) {
    bool lessThan = false;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        if (a[i] < b[i]) {
            lessThan = true;
            break;
        } else if (a[i] > b[i])
            break;
    }
    return lessThan;
}

string gen_random(const int len) {
    static const char alphanum[] = "0123456789"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz";
    string tmp;
    for (int i = 0; i < len; ++i) {
        tmp += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp;
}

void testCompare() {
    string a;
    string b;
    bool cmp;
    for (int i = 0; i < 1000; i++) {
        a = gen_random(rand() % 100);
        b = gen_random(rand() % 100);
        cmp = (a < b);
        if (cmp != compare(a, b)) {
            cout << a << "\n" << b;
            assert (false);
        }
    }
    cout << "PERFECT !!!!!!";
}

int main() {
    cout << compare("ab", "ca") << "\n";
    testCompare();
    return 0;
}
