#include <iostream>
#include <cmath>

using namespace std;

// Gives the prime numbers up to the range
void sieve(int range) {
    bool arr[range] = {false, false};
    for (int i = 2; i < range; i++)
        arr[i] = true;
    for (int i = 2; i < sqrt(range); i++)
        if (arr[i])
            for (int j = i + 1; j < range; j++)
                if (j % i == 0)
                    arr[j] = false;
    for (int i = 0; i < range; i++)
        if (arr[i])
            cout << i << "  ";
}

int main() {
    sieve(25);
    return 0;
}