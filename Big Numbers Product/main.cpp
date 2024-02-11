#include <bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef vector<int> vi;

void removeLeadingZeros(vector<int> &num) {
    while (num.size() > 1 && num.back() == 0)
        num.pop_back();
}

// Performs multiplication on big numbers
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    while (getline(cin, s) && !s.empty()) {
        // Convert characters to integers and reverse the vectors
        vi a, b;
        for (char c: s)
            a.push_back(int(c - '0'));
        reverse(all(a));

        getline(cin, s);
        for (char c: s)
            b.push_back(int(c - '0'));
        reverse(all(b));

        // Initialize result vector with zeros
        vi res(sz(a) + sz(b), 0);

        for (int i = 0; i < sz(b); i++) {
            for (int j = 0; j < sz(a); j++) {
                res[j + i] += b[i] * a[j];
                res[j + i + 1] += res[j + i] / 10;
                res[j + i] = res[j + i] % 10;
            }
        }

        removeLeadingZeros(res);

        reverse(all(res));
        for (int digit: res)
            cout << digit;
        cout << '\n';
    }
    return 0;
}
