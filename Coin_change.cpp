
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // Create a dp array to store the number of ways to make each sum
      vector<int> dp(sum + 1, 0);

        // There's exactly one way to make sum 0 (by using no coins)
        dp[0] = 1;

        // Iterate through all coins
        for (int i = 0; i < N; i++) {
            // For each coin, update the dp array for all sums greater than or equal to that coin
            for (int j = coins[i]; j <= sum; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        // Return the number of ways to make the sum
        return dp[sum];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}