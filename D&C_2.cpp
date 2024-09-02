//{ Driver Code Starts

//Allocate Minimum Pages

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if (m > n) return -1; // added this line
        long long low = *max_element(arr, arr + n);
        long long high = accumulate(arr, arr + n, 0LL);
        long long result = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int students = 1;
            long long curr_sum = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] > mid) break;
                if (curr_sum + arr[i] > mid) {
                    students++;
                    curr_sum = arr[i];
                } else {
                    curr_sum += arr[i];
                }
            }
            if (students <= m) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends