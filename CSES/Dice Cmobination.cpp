#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int mod = 1e9 + 7;
int ans = 0;

int main(){
    int n;
    cin >> n;
    
    solve(n);

    cout << ans;

    return 0;
}