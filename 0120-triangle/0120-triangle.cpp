class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        int n= triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        int ans= helper(triangle, 0, 0, m, dp);
        return ans;
    }
    int helper(vector<vector<int>>& arr, int i, int j, int& m, vector<vector<int>>& dp){
        if(i==(m-1)) return arr[i][j];
        if(dp[i][j]!= INT_MAX) return dp[i][j];
        int d= arr[i][j]+ helper(arr, i+1, j, m, dp);
        int d2= arr[i][j]+ helper(arr, i+1, j+1, m, dp);
        return dp[i][j]= min(d,d2);
    }
};