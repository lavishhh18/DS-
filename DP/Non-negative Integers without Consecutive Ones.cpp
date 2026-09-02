//Leetcode - 600
class Solution {
public:
    int dp[31][2][3];
    int solve(string& s, int i, bool tight, int prev){
        if(i == s.size()) return 1;

        if(dp[i][tight][prev] != -1) return dp[i][tight][prev];

        int ub = tight ? s[i] - '0' : 1;
        int cnt = 0;

        for(int bit = 0; bit <= ub; bit++){
            if(prev == 1 && bit == 1) continue; //pichla banda 1 ho and curr bhi 1
            bool newTight = (tight && bit == ub);

            cnt += solve(s, i + 1, newTight, bit);
        }

        return dp[i][tight][prev] = cnt;
    }

    int findIntegers(int n) {
        string s = "";
        while(n > 0){
            char currBit = 1 & n;
            s += '0' + currBit;

            n = n >> 1;
        }
        reverse(s.begin(), s.end());

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 1, 2);
    }
};