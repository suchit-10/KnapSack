 bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int w = sum;
        vector<vector<bool>>dp(n + 1,vector<bool>(w+1,false));
        for(int j = 0 ; j<=w ; j++){
            dp[0][j] = false;
        }
        for(int i=0 ; i<=n ; i++){
            dp[i][0] = true;
        }
        for(int i=1 ; i<=n ; i++){
            for(int j = 1 ; j<=w ; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }