#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
int n;

// int solve(int i, int target, vector<int>& pages, vector<int>& price, vector<vector<int>>& dp){
//     if(target == 0){
//         return 0;
//     }
//     if(i == n-1){
//         if(target - price[i] == 0){
//             return pages[i];
//         }
//         return 0;
//     }

//     if(dp[i][target] != -1) return dp[i][target];

//     int pgs = 0;

//     if(target - price[i] >= 0){
//         pgs = max(pgs, pages[i] + solve(i + 1, target - price[i], pages, price, dp));
//     }

//     pgs = max(pgs, solve(i + 1, target, pages, price, dp));

//     return dp[i][target] = pgs;
// }


int main() {
    int N, x;
    cin >> N >> x;
    n = N;
    vector<int> price(n);
    vector<int> pages(n);

    for(int i = 0; i<n; i++){
        cin >> price[i];
    }
    for(int i = 0; i<n; i++){
        cin >> pages[i];
    }

    vector<int> next(x + 1, 0);
    vector<int> curr(x + 1, 0);

    for(int target = 0; target <= x; target++){
        if(target >= price[n-1]){ //price can be atmost X, that means it can be less than X too
            next[target] = pages[n-1];
        }
    }

    for(int i = n-2; i>=0; i--){
        for(int target = 0; target <= x; target++){
            int pgs = 0;

            if(target >= price[i]){
                pgs = max(pgs, pages[i] + next[target - price[i]]);
            }

            pgs = max(pgs, next[target]);

            curr[target] = pgs;
        }
        next = curr;
    }
    cout << next[x];

    return 0;
}