#include <iostream>
using namespace std;

// Function to find the maximum profit
int maxProfit(int prices[], int n) {
    int profit = 0;

    // Traverse through the array
    for (int i = 1; i < n; i++) {
        // If the current day's price is higher than the previous day's,
        // accumulate the difference (profit)
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

// Driver Code
int main() {
    // Example array of prices
    int prices[] = {2, 3, 5};
    int N = sizeof(prices) / sizeof(prices[0]);

    // Function Call
    cout << "Maximum Profit: " << maxProfit(prices, N) << endl;

    return 0;
}
