//Given an array arr of non-negative integers and an integer target, 
//the task is to count all subsets of the array whose sum is equal to the given target.

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int w = target;
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        for(int j=0 ; j<=w ; j++)dp[0][j] = 0;
        for(int i=0 ; i<=n ; i++)dp[i][0] = 1;
        
        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<=w; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j- arr[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
};