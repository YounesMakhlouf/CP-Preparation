#include <iostream>

using namespace std;

// Function to find the maximum subarray sum using a brute force approach (O(n^3))
int v1(const int t[], int n)
{
    int best = 0;
    for (int a = 0; a < n ; a++)
        for (int b = a; b < n; b++)
        {
            int sum = 0;
            for (int k = a; k <= b; k++)
                sum += t[k];
            best = max(best, sum);
        }
    return best;
}


// Function to find the maximum subarray sum using a more efficient approach (O(n^2))
int v2(const int t[], int n)
{
    int best = 0;
    for (int a = 0; a < n ; a++)
    {
        int sum = 0;
        for (int b = a; b < n; b++)
        {
            sum += t[b];
            best = max(best, sum);
        }
    }
    return best;
}

// Function to find the maximum subarray sum using Kadane's algorithm (O(n))
int v3(int t[], int n)
{
    int best = 0, sum = 0;
    for (int k = 0; k < n ; k++)
    {
        sum = max(t[k], sum+t[k]);
        best = max(best, sum);
    }
    return best;
}

int main() {
    // Test cases
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "v1: " << v1(arr, n) << endl;
    cout << "v2: " << v2(arr, n) << endl;
    cout << "v3: " << v3(arr, n) << endl;
    return 0;
}
