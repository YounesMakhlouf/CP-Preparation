#include <iostream>

using namespace std;

// Using pointers to create, print and delete mulit-dimension arrays

int ***create3D(int a, int b, int c) {
    int ***arr = new int **[a];
    for (int i = 0; i < a; i++) {
        arr[i] = new int *[b];
        for (int j = 0; j < b; j++) {
            arr[i][j] = new int[c];
            for (int k = 0; k < c; k++)
                arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
        }
    }
    return arr;
}

void print3d(int ***arr, int a, int b, int c) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++)
                cout << arr[i][j][k] << " ";
            cout << "\t";
        }
        cout << "\n";
    }
}

void free(int ***arr, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            delete[] arr[i][j];
        delete[] arr[i];
    }
    delete[] arr;
}

int **create2D(int a, int b) {
    int **arr = new int *[a];
    for (int i = 0; i < a; i++) {
        arr[i] = new int[b];
        for (int j = 0; j < b; j++)
            arr[i][j] = (i + 1) * (j + 1);
    }
    return arr;
}

void print2D(int **arr, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

void free(int **arr, int a) {
    for (int i = 0; i < a; i++)
        delete[] arr[i];
    delete[] arr;
}

int main() {
    cout << "Aray 1: \n";
    int **arr = create2D(3, 2);
    print2D(arr, 3, 2);
    free(arr, 3);


    cout << "\nArray 2: \n";

    int ***arr2 = create3D(3, 2, 4);
    print3d(arr2, 3, 2, 4);
    free(arr2, 3, 2);
    return 0;
}