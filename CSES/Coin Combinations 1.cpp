#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);

    for(int i = 0; i <n; i++){
        cin >> coins[i];
    }

    vector<int> dp(target + 1, 0);

    sort(coins.begin(), coins.end());

    dp[0] = 1;

    for(int sum = 1; sum<=target; sum++){
        for(auto coin : coins){
            if(coin > sum){
                break;
            }

            dp[sum] += dp[sum - coin];

            if(dp[sum] >= mod){
                dp[sum] -= mod;
            }
        }
    }

    cout << dp[target];

    return 0;
}