class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += arr[i];
        vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= totalSum; j++) {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int minDiff = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[n][s1]) {
                int s2 = totalSum - s1;
                minDiff = min(minDiff, abs(s2 - s1));
            }
        }

        return minDiff;
    }
};
