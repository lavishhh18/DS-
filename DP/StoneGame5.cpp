class Solution {
public:
    int n;
    int solve(int l, int r, vector<vector<int>>& dp, vector<int>& prefix){
        if(l >= r){ //agar ek stone ya 0 bache toh score 0 add hoga
            return 0;
        }

        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for(int i = l; i < r; i++){
            int rightSum = prefix[r+1] - prefix[i+1]; //right range ka sum
            int leftSum = prefix[i+1] - prefix[l]; // left raneg ka sum

            if(leftSum > rightSum){ // if left zyada hai we'll take right and aage recursion ko de denge solve karne
                ans = max(ans, rightSum + solve(i + 1, r, dp, prefix));
            }

            else if(leftSum < rightSum){ // same here 
                ans = max(ans, leftSum + solve(l, i, dp, prefix));
            }

            else { // if left and right arrays ka sum equal hai toh dono arrays ki possibilities ko explore karo
                ans = max(ans, leftSum + max(solve(i + 1, r, dp, prefix), solve(l, i, dp, prefix)));
            }
        }
        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> prefix(n+1, 0);

        for(int i = 1; i<=n; i++){
            prefix[i] = prefix[i-1] + stoneValue[i-1]; // prefix array
        }

        return solve(0, n-1, dp, prefix);
    }
};