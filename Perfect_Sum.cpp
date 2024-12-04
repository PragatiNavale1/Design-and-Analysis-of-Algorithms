//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7; // To avoid overflow
        vector<int> dp(target + 1, 0);

        dp[0] = 1; // There is one way to get a sum of 0: the empty subset.

        for (int num : arr) {
            for (int sum = target; sum >= num; sum--) {
                dp[sum] = (dp[sum] + dp[sum - num]) % MOD;
            }
        }

        return dp[target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target) << endl;
    }

    return 0;
}
// } Driver Code Ends
