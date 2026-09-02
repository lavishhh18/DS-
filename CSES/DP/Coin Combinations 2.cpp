#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

// ll solve(int i, int target, vector<int>& arr, vector<vector<ll>>& dp){
//     if(target == 0) return 1;
//     if(i == n){
//         if(target == 0) return 1;
//         return 0;
//     }

//     if(dp[i][target] != -1) return dp[i][target];

//     ll take = 0;

//     if(target - arr[i] >= 0){
//         take = solve(i, target - arr[i], arr, dp);
//     }

//     ll notTake = solve(i + 1, target, arr, dp);

//     return dp[i][target] = take + notTake;
// }

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);

    vector<int> prev(x + 1, 0);
    vector<int> curr(x + 1, 0);

    for(int i = 0; i < n; i++) cin >> arr[i];

    prev[0] = 1;

    for(int i = n-1; i >= 0; i--){
        fill(curr.begin(), curr.end(), 0);
        for(int target = 0; target <= x; target++){
            int take = 0;
            if(target - arr[i] >= 0){
                take = curr[target - arr[i]] % mod;
            }

            int notTake = prev[target] % mod;

            curr[target] = (take + notTake) % mod;
        }
        prev = curr;
    }

    cout << prev[x];
    return 0;
}