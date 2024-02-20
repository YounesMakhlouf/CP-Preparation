#include <bits/stdc++.h>

using namespace std;

int decalage(int arr[], int pos, int SIZE) {
    for (int i = pos; i < SIZE; i++) {
        arr[i - 1] = arr[i];
    }
    SIZE--;
    return SIZE;
}

int solveJoseph(int n, int k) {
    int circle[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        circle[i] = i + 1;
    while (n > 1) {
        for (int i = 1; i <= n; i++) {
            j++;
            if (j == k) {
                n = decalage(circle, i, n);
                for (int i = 0; i < n; i++)
                    cout << circle[i] << " ";
                cout << "\n";
                j = 0;
                i--;
            }
        }
    }
    cout << circle[0];
}

int solveJosephRecursive(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (solveJosephRecursive(n - 1, k) + k - 1) % n + 1;
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int SIZE = decalage(arr, 0, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << solveJosephRecursive(7, 3);
    return 0;
}
