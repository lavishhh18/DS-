#include <bits/stdc++.h>
#include<iostream>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
ll ans = 0;

ll solve(int sum, vector<ll>& dp){
    if(sum == 0){
        return 1;
    }

    if(dp[sum] != -1) return dp[sum];

    ll take = 0;

    for(int i = 1; i<=6; i++){
        if(sum - i >= 0){
            take = (take +solve(sum - i, dp)) % mod;
        }
    }

    return dp[sum] = take;
}

int main(){
    int n;
    cin >> n;
    vector<ll> dp(n + 1, -1);

    cout << solve(n, dp);
    return 0;
}