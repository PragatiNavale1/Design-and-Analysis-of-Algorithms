#include <bits/stdc++.h>
using namespace std;

// Function to reverse the digits of a number
long long rev(long long n) {
    long long rev_num = 0;
    while (n > 0) {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

// Class containing the function to calculate power
class Solution {
public:
    long long power(int N, int R) {
        // Define the modulo
        long long mod = 1000000007;
        long long result = 1;
        long long base = N;

        // Apply modular exponentiation
        while (R > 0) {
            if (R % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            R /= 2;
        }
        return result;
    }
};

// Driver code
int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        long long N;
        cin >> N;  // Input number N

        long long R = rev(N);  // Compute the reverse of N

        Solution ob;
        long long ans = ob.power(N, R);  // Compute N^R mod 10^9 + 7
        cout << ans << endl;  // Output the result
    }
    return 0;
}
