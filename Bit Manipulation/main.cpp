#include <iostream>
#include <cmath>

using namespace std;
#define INT_BITS 8

// Print the binary representation of an integer n with a specified length len
void printNumber(int n, int len) {
    if (!len)
        return;
    else
        printNumber(n >> 1, len - 1);
    cout << (n & 1);
}

// Counts the number of bits that have the value bitValue
int countNumBits(int n, int bitValue) {
    int res = 0;
    while (n) {
        res += ((n & 1) == bitValue);
        n >>= 1;
    }
    return res;
}

int getBit(int num, int idx) {
    return ((num << idx) & 1) == 1;
}

int setBit1(int num, int idx) {
    return num | (1 << idx);
}

int setBit0(int num, int idx) {
    return num & ~(1 << idx);
}

int flipBit(int num, int idx) {
    return num ^ (1 << idx);
}

int rotation(int n, int d) {
    return ((n >> d) | (n << (INT_BITS - d)));
}

int main() {
    printNumber(7, 8);
    cout << '\n';
    cout << countNumBits(8, 1) << '\n';
    cout << countNumBits(8, 0) << '\n';
    cout << setBit0(7, 1) << '\n';
    cout << setBit1(7, 6) << '\n';
    cout << rotation(229, 3) <<  '\n';
    cout << __builtin_popcount(12);
    cout << __builtin_popcount(40);
    return 0;
}