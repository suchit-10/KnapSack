//Slight variation of countPartitions almost similer.

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++)sum+=nums[i];
        if ((target + sum) % 2 != 0 || sum < abs(target)) return 0;
        int w = (target + sum) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= w; ++j) {
                if (nums[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]) % mod;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][w];
    }
};
