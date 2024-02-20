#include <bits/stdc++.h>

using namespace std;

void printCycles(int arr[], int SIZE) {
    int initial[SIZE];
    for (int i = 0; i < SIZE; i++)
        initial[i] = i;
    int pos = 0;
    int used[SIZE];
    for (int i = 0; i < SIZE; i++) {
        if (find(used, used + i, initial[pos]) == used + i)
            cout << initial[pos] << " -> " << arr[pos] << "\n";
        else {
            sort(used, used + i);
            pos = used[i - 1] + 1;
            cout << initial[pos] << " -> " << arr[pos] << "\n";
        }
        used[i] = initial[pos];
        pos = arr[pos];
    }
}

int main() {
    int arr[] = {2, 0, 1, 4, 3, 5};
    printCycles(arr, sizeof(arr) / sizeof(arr[0]));
}