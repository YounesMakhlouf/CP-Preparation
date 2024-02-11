#include <iostream>
using namespace std;

const int ROWS = 3, COLS = 4;

// Gives the index of an element in a 3D array if it were flattened into a 1D array.
int calculateIndex(int r, int c, int h) {
    return (r * COLS + c) + COLS * ROWS * h;
}

int main() {
    int r = 1, c = 3, h = 1;
    int idx = calculateIndex(r, c, h);
    cout << "Index: " << idx << endl;
    return 0;
}