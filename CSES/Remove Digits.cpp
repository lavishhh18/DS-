#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

// int solve(int n, vector<int>& dp){
//     if(n == 0){
//         return 0;
//     }

//     if(dp[n] != -1) return dp[n];
//     int ans = INT_MAX;
//     int temp = n;

//     while(temp > 0){
//         int curr = temp % 10;
//         if(curr == 0) {
//             temp = temp / 10;
//             continue;
//         }
//         int steps = 0;

//         if(n - curr >= 0){
//             steps = 1 + solve(n - curr, dp);
//         }
        
//         ans = min(ans, steps);
//         temp = temp / 10;
//     }

//     return dp[n] = ans;
// }

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    for(int i = 1; i<= n; i++){
        int ans = INT_MAX;
        int temp = i;

        while(temp > 0){
            int curr = temp%10;
                if(curr == 0) {
                temp = temp / 10;
                continue;
            }

            int steps = 0;

            if(i - curr >= 0){
                steps = 1 + dp[i - curr];
            }

            ans = min(ans, steps);
            temp = temp / 10;
        }
        dp[i] = ans;
    }

    cout << dp[n];
    return 0;
}