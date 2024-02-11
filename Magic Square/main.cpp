#include <iostream>
#include <cassert>

using namespace std;

const int N = 3;
enum dir {
    DOWN = 0, RIGHT, UP, LEFT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
};
int dir_r[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dir_c[] = {0, 1, 0, -1, -1, 1, -1, 1};

// method 1
int sumRow(int i, int square[N][N]) {
    int sum = 0;
    for (int j = 0; j < N; j++)
        sum += square[i][j];
    return sum;
}

int sumCol(int i, int square[N][N]) {
    int sum = 0;
    for (int j = 0; j < N; j++)
        sum += square[j][i];
    return sum;
}

int sumMainDiag(int square[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += square[i][i];
    return sum;
}

int sumAntiDiag(int square[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += square[i][N - i - 1];
    return sum;
}

bool magic(int square[N][N]) {
    assert(N == N);
    int sum = sumCol(0, square);
    for (int i = 0; i < N; i++) {
        if (sum != sumCol(i, square))
            return false;
        if (sum != sumRow(i, square))
            return false;
    }
    if ((sum != sumMainDiag(square)) || (sum != sumAntiDiag(square)))
        return false;
    return true;
}

//method 2: Using directions
int sum(int square[N][N], int r, int c, dir dir, int steps) {
    int sum = 0;
    for (int s = 0; s < steps; s++) {
        sum += square[r][c];
        r += dir_r[dir];
        c += dir_c[dir];
    }
    return sum;
}

bool validate(int square[N][N]) {
    int val = sum(square, 0, 0, RIGHT, N);
    for (int i = 0; i < N; i++) {
        if (val != sum(square, 0, i, DOWN, N))
            return false;
        if (val != sum(square, i, 0, RIGHT, N))
            return false;
    }
    if (val != sum(square, 0, 0, DOWN_RIGHT, N))
        return false;
    if (val != sum(square, 0, N - 1, DOWN_LEFT, N))
        return false;
    return true;
}

int main() {
    int square[N][N] = {{8, 1, 6},
                        {3, 5, 7},
                        {4, 9, 2}};
    cout << validate(square);
    square[0][0]++;
    cout << validate(square);
    return 0;
}
