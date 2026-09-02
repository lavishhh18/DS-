#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    if(arr[0][0] == '*' || arr[n-1][n-1] == '*') {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[n-1][n-1] = 1;

    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(i == n-1 && j == n-1) continue;

            if(arr[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }

            int down = 0;
            int right = 0;

            if(i + 1 < n && arr[i + 1][j] == '.'){
                down = dp[i + 1][j];
            }

            if(j + 1 < n && arr[i][j + 1] == '.'){
                right = dp[i][j + 1];
            }

            dp[i][j] = (right + down) % mod;
        }
    }

    cout << dp[0][0];

    return 0;
}