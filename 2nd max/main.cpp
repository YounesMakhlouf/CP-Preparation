#include <iostream>
#include <algorithm>

using namespace std;

const int ROWS = 3, COLS = 4;

int get2ndMax(int t[], int s) {
    int m = 0;
    for (int i = 1; i < s; i++) {
        if (t[i] > t[m])
            m = i;
    }
    t[m] = -1;
    int m2 = t[0];
    for (int i = 1; i < s; i++) {
        if (t[i] > m2)
            m2 = t[i];
    }
    return m2;
}

int getMatrix2ndMax(int mat[ROWS][COLS]) {
    int m = mat[0][0], m2 = mat[0][1];
    if (m2 > m)
        swap(m2, m);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            if (mat[i][j] > m) {
                m2 = m;
                m = mat[i][j];
            } else if (mat[i][j] > m2)
                m2 = mat[i][j];
        }
    return m2;
}

// Calculates the maximum sum of consecutive k elements in an array t of size n
int getsubmax(const int t[], int n, int k) {
    int m = 0;
    for (int i = 0; i < k; i++)
        m += t[i];
    for (int i = 1; i <= n - k; i++) {
        int s = 0;
        for (int j = i; j < k + i; j++)
            s += t[j];
        if (s > m)
            m = s;
    }
    return m;
}

int getsubmax_v2(const int t[], int n, int k) {
    int m = 0;
    for (int i = 0; i < k; i++)
        m += t[i];
    int s = m;
    for (int i = 0; i < n - k; i++) {
        s = s - t[i] + t[i + k];
        if (s > m)
            m = s;
    }
    return m;
}

int main() {
    int t[] = {1, -3, 2, 1, -1, 4, -2, 3};
    int n = sizeof(t) / sizeof(t[0]);
    int k = 3;

    int max_sum = getsubmax(t, n, k);
    cout << "Maximum sum of consecutive " << k << " elements: " << max_sum << endl;

    return 0;
}