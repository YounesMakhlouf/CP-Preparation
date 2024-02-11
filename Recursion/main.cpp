#include <iostream>

using namespace std;
const int MAX = 5;
char maze[MAX][MAX] = {'.', 'S', 'X', '.', '.', '.', '.', 'X', '.', 'E', '.', '.', '.', '.', 'X', 'X', '.', 'X', 'X',
                       '.'};
bool vis[MAX][MAX];

bool valid(int r, int c) {
    return (r >= 0 && r < MAX && c >= 0 && c < MAX);
}

// finds the end of a maze (represented by 'E')
bool findEnd(int r, int c) {
    if (!valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
        return false;
    vis[r][c] = true;
    if (maze[r][c] == 'E')
        return true;

    if (findEnd(r, c - 1) || findEnd(r, c + 1) || findEnd(r - 1, c) || findEnd(r + 1, c))
        return true;

    vis[r][c] = false;

    return false;
}

int cnt = 0;

void floodFillCnt(int r, int c) {
    if (!valid(r, c) || maze[r][c] == 'X' || vis[r][c])
        return;
    vis[r][c] = true;
    cnt++;
    floodFillCnt(r, c - 1);
    floodFillCnt(r, c + 1);
    floodFillCnt(r - 1, c);
    floodFillCnt(r + 1, c);
}

int cntComponents(int R, int C) {
    int comps = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; i < C; i++) {
            cnt = 0;
            floodFillCnt(i, j);
            if (cnt > 0)
                comps++;
        }
    return comps;
}


void perm(int i, int n, int vis[], int cur[]) {
    if (i == n) {
        for (int j = 0; j < n; j++)
            cout << cur[j];
        cout << "\n";
        return;
    }

    for (int j = 0; j < n; j++)
        if (!vis[j]) {
            vis[j] = 1;
            cur[i] = j;
            perm(i + 1, n, vis, cur);
            vis[j] = 0;
        }
}

void comb(int i, int n, int m, int cur[], int curLen) {
    if (curLen == m) {
        for (int j = 0; j < m; j++)
            cout << cur[j];
        cout << "\n";
        return;
    }
    if (i == n)
        return;
    cur[curLen] = i;
    comb(i + 1, n, m, cur, curLen + 1);
    comb(i + 1, n, m, cur, curLen);
}


int main() {
    int n = 3;
    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    int res[n];

    /*  for (int i = 0; i < MAX; i++)
      {
          for (int j = 0; j < MAX; j++)
              cout << maze [i][j];
          cout << "\n";
      }
      for (int i = 0; i < MAX; i++)
          for (int j = 0; j < MAX; j++)
              if (maze[i][j] == 'S')
              {
                  cout << i << " " << j << "\n";
                  cout << findEnd(i,j);
                  break;
              }*/

    perm (0, n, vis, res);
//    comb(0, n, 2, res, 0);
    return 0;
}
