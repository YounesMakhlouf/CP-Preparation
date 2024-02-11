#include <bits/stdc++.h>

using namespace std;
const int N = 100;
enum dir {
    DOWN = 0, RIGHT, UP, LEFT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
};
int dir_r[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dir_c[] = {0, 1, 0, -1, -1, 1, -1, 1};


void odd(int square[N][N], int N) {
    int cnt = 1, i = 0, j = N / 2;
    for (int k = 0; k < N; k++) {
        for (int r = 1; r < N; r++) {
            square[i][j] = cnt;
            i = (i - 1) % N;
            if (i < 0)
                i += N;
            j = (j + 1) % N;
            cnt++;
        }
        square[i][j] = cnt;
        cnt++;
        i++;
    }
}

void doubly_even(int square[N][N], int N) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            square[i][j] = (N * i) + j + 1;
    for (i = 0; i < N / 4; i++)
        for (j = 0; j < N / 4; j++)
            square[i][j] = (N * N + 1) - square[i][j];
    for (i = 0; i < N / 4; i++)
        for (j = 3 * (N / 4); j < N; j++)
            square[i][j] = (N * N + 1) - square[i][j];
    for (i = 3 * N / 4; i < N; i++)
        for (j = 0; j < N / 4; j++)
            square[i][j] = (N * N + 1) - square[i][j];
    for (i = 3 * N / 4; i < N; i++)
        for (j = 3 * N / 4; j < N; j++)
            square[i][j] = (N * N + 1) - square[i][j];
    for (i = N / 4; i < 3 * N / 4; i++)
        for (j = N / 4; j < 3 * N / 4; j++)
            square[i][j] = (N * N + 1) - square[i][j];
}

void singly_even(int square[N][N], int N) {
    int quadrant[100][100];
    int i, j;
    odd(quadrant, N / 2);
    for (i = 0; i < N / 2; i++)
        for (j = 0; j < N / 2; j++)
            square[i][j] = quadrant[i][j];
    for (i = N / 2; i < N; i++)
        for (j = N / 2; j < N; j++)
            square[i][j] = quadrant[i - N / 2][j - N / 2] + (N * N / 4);
    for (i = 0; i < N / 2; i++)
        for (j = N / 2; j < N; j++)
            square[i][j] = quadrant[i][j - N / 2] + (N * N / 2);
    for (i = N / 2; i < N; i++)
        for (j = 0; j < N / 2; j++)
            square[i][j] = quadrant[i - N / 2][j] + (3 * N * N / 4);
    for (i = 0; i < N / 4; i++)
        for (j = 0; j < N / 4; j++)
            swap(square[i][j], square[i + N / 2][j]);
    for (j = 1; j <= N / 4; j++)
        swap(square[N / 4][j], square[3 * N / 4][j]);
    for (i = N / 4 + 1; i < N / 2; i++)
        for (j = 0; j < N / 4; j++)
            swap(square[i][j], square[i + N / 2][j]);
    for (i = 0; i < ((N / 2 - 1) / 2) - 1; i++)
        for (j = 0; j < N / 2; j++)
            swap(square[j][N - 1 - i], square[j + N / 2][N - 1 - i]);
}

void print_matrix(int square[N][N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(3) << square[i][j] << "  ";
        cout << "\n";
    }
}

void generate_magic_square(int square[N][N], int N) {
    if (N % 2 != 0)
        odd(square, N);
    else if (N % 4 == 0)
        doubly_even(square, N);
    else
        singly_even(square, N);
    print_matrix(square, N);
}

// check if result is a magic square
int sum(int square[N][N], int r, int c, dir dir, int steps) {
    int sum = 0;
    for (int s = 0; s < steps; s++) {
        sum += square[r][c];
        r += dir_r[dir];
        c += dir_c[dir];
    }
    return sum;
}

bool validate(int square[N][N], int N) {
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
    int s;
    cout << "Give the size of the matrix\t";
    cin >> s;
    cout << "\n\n";
    int square[N][N];
    generate_magic_square(square, s);
    cout << "\n\n";
    if (validate(square, s))
        cout << "YESS! IT'S MAAAAGGGIIIICCCC!!!!";
    else
        cout << "I see no magic square";
    return 0;
}
