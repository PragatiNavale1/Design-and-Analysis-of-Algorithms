#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    int n = S.size();
    vector<pair<int, int>> shops(n);

    // Pair the start and end times and sort them by the end time
    for (int i = 0; i < n; i++) {
        shops[i] = {E[i], S[i]};
    }
    
    sort(shops.begin(), shops.end());

    // Array to keep track of the end time for each of the K persons
    vector<int> endTimes(K, 0);
    int count = 0;

    for (int i = 0; i < n; i++) {
        int start = shops[i].second;
        int end = shops[i].first;

        // Try to find a person who can take this activity
        for (int j = 0; j < K; j++) {
            if (endTimes[j] <= start) {
                endTimes[j] = end;
                count++;
                break;
            }
        }
    }

    return count;
}

int main() {
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << maxShopsVisited(S1, E1, K1) << endl;  // Output: 4

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << maxShopsVisited(S2, E2, K2) << endl;  // Output: 3

    return 0;
}
