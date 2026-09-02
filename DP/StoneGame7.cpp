class Solution {
public:
    int n;
    int solve(int l, int r, vector<int>& prefix, vector<vector<int>>& dp){
        if(l == r){
            return 0;
        }

        if(dp[l][r] != -1) return dp[l][r];

        int rightSum = prefix[r + 1] - prefix[l + 1];
        int leftSum = prefix[r] - prefix[l];

        int left =  rightSum - solve(l + 1, r, prefix, dp);
        int right = leftSum - solve(l, r - 1, prefix, dp);

        return dp[l][r] = max(left, right);
    }

    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        vector<int> prefix(n + 1, 0);

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 1; i<=n; i++){
            prefix[i] = prefix[i-1] + stones[i-1];
        }

        return solve(0, n-1, prefix, dp);
    }
};