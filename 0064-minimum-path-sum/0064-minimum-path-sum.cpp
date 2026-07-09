class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans= helper(grid, 0, 0, m, n, dp);
        return ans;
    }
    int helper(vector<vector<int>>&grid, int i, int j, int& m, int& n, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!= -1) return dp[i][j];
        int r= INT_MAX;
        int d= INT_MAX;
        if((j+1)<n) r= grid[i][j]+ helper(grid, i, j+1, m, n, dp);
        if((i+1)<m) d= grid[i][j]+ helper(grid, i+1, j, m, n, dp);
        return dp[i][j]=min(r,d);
    }
};