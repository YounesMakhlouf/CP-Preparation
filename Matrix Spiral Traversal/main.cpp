#include <iostream>

using namespace std;

enum dir {
    RIGHT = 0, DOWN, LEFT, UP
};
int dir_c[] = {1, 0, -1, 0};
int dir_r[] = {0, 1, 0, -1};
const int N = 6;

void spiralTraversal(int square[N][N], int N) {
    int r = 0, c = 0, s = N - 1, dir = 0;
    while (s > 0) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < s; i++) {
                cout << square[r][c] << "  ";
                r += dir_r[dir];
                c += dir_c[dir];
            }
            dir = (dir + 1) % 4;
        }
        c++;
        r++;
        s -= 2;
    }
    if (N % 2 != 0)
        cout << square[r][c];
}

int main() {
    int square[N][N];
    int s = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            square[i][j] = s;
            s++;
        }
    cout << "Original matrix\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n Spiral Traversal:\n";
    spiralTraversal(square, 6);
    return 0;
}