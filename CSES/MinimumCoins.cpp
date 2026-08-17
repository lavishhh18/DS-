#include <bits/stdc++.h>
#include<iostream>

using namespace std;
using ll = long long;

// int solve(int target, vector<int>& dp, vector<int>& coins){
//     if(target == 0){
//         return 0;
//     }

//     if(dp[target] != 1e9) return dp[target];

//     int take = 1e9;

//     for(int i = 0; i<coins.size(); i++){
//         if(target - coins[i] >= 0){
//             int temp = solve(target - coins[i], dp, coins);

//             if(temp != 1e9){
//                 take = min(take, 1 + temp);
//             }
//         }
//     }

//     return dp[target] = take;
// }

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);

    for(int i = 0; i <n; i++){
        cin >> coins[i];
    }

    vector<int> dp(target + 1, 1e9);

    dp[0] = 0;

    for(int sum = 1; sum<=target; sum++){
        int take = 1e9;
        for(int j = 0; j<coins.size(); j++){
            if(sum - coins[j] >= 0){
                int temp = dp[sum - coins[j]];

                if(temp != 1e9){
                    take = min(take, 1 + temp);
                }
            }
        }
        dp[sum] = take;
    }

    cout << (dp[target] == 1e9 ? -1 : dp[target]);

    return 0;
}