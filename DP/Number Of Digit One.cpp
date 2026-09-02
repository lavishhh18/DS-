// Leetcode-223 : Digit DP

class Solution {
public:
    int dp[11][2][10];
    int solve(int i, bool tight, int cntOfOnes, string& s){
        if(i == s.size()) return cntOfOnes;

        if(dp[i][tight][cntOfOnes] != -1) return dp[i][tight][cntOfOnes];

        int ub = (tight == 1) ? (s[i] - '0') : 9;
        int cnt = 0;
        
        for(int digit = 0; digit <= ub; digit++){
            //if digit is 1 increase count of Ones by 1
            cnt += solve(i + 1, (tight && digit == ub), cntOfOnes + (digit == 1), s);
        }

        return dp[i][tight][cntOfOnes] = cnt;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 1, 0, s);
        return ans;
    }
};