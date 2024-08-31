//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int size1 = arr1.size();
        int size2 = arr2.size();

        // Create a new array with the combined size
        vector<int> result(size1 + size2);
        for (int i = 0; i < size1; i++) {
            result[i] = arr1[i];
        }
        for (int i = 0; i < size2; i++) {
            result[i + size1] = arr2[i];
        }
        
        // Sort the combined result array
        sort(result.begin(), result.end());

        // Return the k-th element
        return result[k - 1];
    }
        
        
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends