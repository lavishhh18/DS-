//leetcode - 902
class Solution {
public:
    int maxi = INT_MIN;
    unordered_set<int> digits;
    int dp[11][2][2];
    
    int solve(string& s, int i, bool tight, bool lz){
        if(i == s.size()){
            if(!lz){
                return 1;
            }
            return 0;
        }

        if(dp[i][tight][lz] != -1) return dp[i][tight][lz];

        int ub = tight ? s[i] - '0' : maxi;

        int cnt = 0;

        for(int dig = 0; dig <= ub; dig++){
            if(digits.find(dig) != digits.end()){
                bool newTight = tight && dig == ub;
                bool newLz = lz && dig == 0;
                if(!lz && dig == 0) continue;
                cnt += solve(s, i + 1, newTight, newLz);
            }
        }
        return dp[i][tight][lz] = cnt;
    }

    int atMostNGivenDigitSet(vector<string>& d, int n) {
        string s = to_string(n);
        for(auto it : d){
            int num = stoi(it);
            digits.insert(num);
            maxi = max(maxi, num);
        }
        digits.insert(0);

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 1, 1);
    }
};