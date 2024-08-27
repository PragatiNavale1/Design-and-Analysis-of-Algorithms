//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n = arr1.size();
    int i = 0, j = 0, count = 0;
    int m1 = -1, m2 = -1;

    // Since we need to find the n-th and (n-1)-th elements,
    // we only need to traverse up to n+1 elements.
    for (count = 0; count <= n; count++) {
        if (i == n) {  // If all elements of arr1[] are smaller than first element of arr2[]
            m1 = m2;
            m2 = arr2[0];
            break;
        } else if (j == n) {  // If all elements of arr2[] are smaller than first element of arr1[]
            m1 = m2;
            m2 = arr1[0];
            break;
        }

        if (arr1[i] <= arr2[j]) {
            m1 = m2;  // Store the previous middle
            m2 = arr1[i];
            i++;
        } else {
            m1 = m2;  // Store the previous middle
            m2 = arr2[j];
            j++;
        }
        
    }
    return m1 + m2;
    }

    

};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends