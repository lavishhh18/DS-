#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N, M;

void minDays(vector<int>& monsters, vector<pair<int, int>>& heroes){
    N = monsters.size();
    M = heroes.size();

    vector<int> best(N+1, 0);

    for(auto& it : heroes){
        int power = it.first;
        int endurance = it.second;

        endurance = min(endurance, N);
        best[endurance] = max(power, best[endurance]);
    }

    for(int i = N-1; i>=1; i--){
        best[i] = max(best[i], best[i+1]);
    }

    int i = 0;
    int days = 0;

    while(i < N){
        int mx = 0;
        int j = i;

        while(j < N){
            mx = max(mx, monsters[j]);

            if(best[j - i + 1] < mx){
                break;
            }

            j++;
        }

        if(i == j){
            cout << -1 << endl;
            return;
        }

        days++;
        i = j;
    }
    cout << days << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vector<int> monsters(n);
        for(int i = 0; i<n; i++){
            cin >> monsters[i];
        }  

        cin >> m;
        vector<pair<int, int>> heroes(m);
        for(int i = 0; i<m; i++){
            cin >> heroes[i].first;
            cin >> heroes[i].second;
        }

        minDays(monsters, heroes);
    }
    return 0;
}