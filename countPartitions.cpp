class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        int sum=0;
        for(int i=0 ; i<n ; i++)sum+=arr[i];
        if ((sum + d) % 2 != 0 || sum < d) return 0;
        int target = (sum + d) / 2;
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for(int i=0 ; i<=n ; i++)dp[i][0]=1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};
