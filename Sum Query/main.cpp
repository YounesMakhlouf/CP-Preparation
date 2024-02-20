#include <bits/stdc++.h>

using namespace std;

// Calculate sum over an array from index s to e on q queries using prefix sum
int main() {
    int n, q;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 1; i < n; i++)
        t[i] += t[i - 1];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        if (s == 0)
            cout << "Query(" << s << ", " << e << ") = " << t[e] << "\n";
        else
            cout << "Query(" << s << ", " << e << ") = " << t[e] - t[s - 1] << "\n";
    }
}