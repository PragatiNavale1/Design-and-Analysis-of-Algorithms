//Trailing zeroes in factorial
// Divide and Conqure

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int count = 0;
        for (int i = 5; N / i >= 1; i *= 5) {
            count += N / i;
        }
        return count;
    }

    int FindtrailingZeroes(int N)
    {
        if (N == 0) return 0;

        int low = 0;
        int high = 5 * N;  // an upper bound guess

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (trailingZeroes(mid) < N) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends