// arr: input array
// n: size of array
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid is a peak element
            if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
                return mid;
            }
            // If the element to the left of mid is greater, then the peak must be on the left side
            else if (mid > 0 && arr[mid - 1] > arr[mid]) {
                high = mid - 1;
            }
            // If the element to the right of mid is greater, then the peak must be on the right side
            else {
                low = mid + 1;
            }
        }
        
        return -1; // This will never be reached
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], tmp[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            tmp[i] = a[i];
        }
        bool f = 0;
        Solution ob;
        
        int A = ob.peakElement(tmp, n);
        
        if(A < 0 || A >= n)
            cout << 0 << endl;
        else
        {
            if(n == 1 && A == 0)
                f = 1;
            else if(A == 0 && a[0] >= a[1])
                f = 1;
            else if(A == n - 1 && a[n - 1] >= a[n - 2])
                f = 1;
            else if(a[A] >= a[A + 1] && a[A] >= a[A - 1])
                f = 1;
            else
                f = 0;
            cout << f << endl;
        }
    }

    return 0;
}
// } Driver Code Ends
