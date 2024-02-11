#include <bits/stdc++.h>

using namespace std;

// This uses the inclusion exclusion principle (https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle) to count the number of elements that are divisible by 2 or 3 or 5
int main() {
    int n, res = 0;
    cin >> n;
    for (int id2 = 0; id2 < 2; id2++)
        for (int id3 = 0; id3 < 2; id3++)
            for (int id5 = 0; id5 < 2; id5++) {
                int d = 1, cntElements = 0;
                if (id2) {
                    d *= 2;
                    cntElements++;
                }
                if (id3) {
                    d *= 3;
                    cntElements++;
                }
                if (id5) {
                    d *= 5;
                    cntElements++;
                }

                if (!cntElements)
                    continue;

                int sign = ((cntElements % 2) == 1) ? 1 : -1;
                res += sign * n / d;
            }
    cout << res;
    return 0;
}
