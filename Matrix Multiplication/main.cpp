#include <iostream>
#include <cassert>

using namespace std;

const int ROWS1 = 2, COLS1 = 3, ROWS2 = 3, COLS2 = 2;

void multiplyMatrices(const int arr1[ROWS1][COLS1], const int arr2[ROWS2][COLS2], int arr3[ROWS1][COLS2]) {
    assert(COLS1 == ROWS2);

    for (int r = 0; r < ROWS1; r++)
        for (int c = 0; c < COLS2; c++)
            arr3[r][c] = 0;

    for (int r = 0; r < ROWS1; r++)
        for (int k = 0; k < COLS1; k++)
            for (int c = 0; c < COLS2; c++)
                arr3[r][c] += arr1[r][k] * arr2[k][c];
}

int main() {
    int matrix1[ROWS1][COLS1] = {{1, 2, 3},
                                 {4, 5, 6}};
    int matrix2[ROWS2][COLS2] = {{7,  8},
                                 {9,  10},
                                 {11, 12}};
    int resultMatrix[ROWS1][COLS2];

    multiplyMatrices(matrix1, matrix2, resultMatrix);

    // Print the result matrix
    for (auto &r: resultMatrix) {
        for (int c: r)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
