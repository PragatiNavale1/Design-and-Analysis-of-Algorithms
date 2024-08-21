// Count the no. of Zeroes
// Divide and Conqure

#include<iostream>                                                                                                                                                                 #include <iostream>
using namespace std;

int countZeroes(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    // Binary search to find the first occurrence of 0
    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if mid is the first occurrence of 0
        if (arr[mid] == 0 && (mid == 0 || arr[mid - 1] == 1)) {
            return n - mid;
        }
        // If the middle element is 1, search in the right half
        else if (arr[mid] == 1) {
            low = mid + 1;
        }
        // If the middle element is 0 but not the first occurrence
        //search in the left half
        else {
            high = mid - 1;
        }
    }
    
    // If there are no 0s in the array
    return 0;
}

int main() {
    int arr1[] = {1, 1, 1, 1, 0, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Number of 0s: " << countZeroes(arr1, n1) << endl;
    
    return 0;
}