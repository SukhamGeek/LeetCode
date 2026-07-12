class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n,-1)));
        int ans= helper(0, 0, n-1, dp, m, n, grid);
        return ans;
    }
    int helper(int i, int j1, int j2, vector<vector<vector<int>>>& dp, int& m, int& n, vector<vector<int>>& grid){
        if(j1<0 || j1==n || j2<0 || j2==n) return 0;
        if(i==(m-1)){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+ grid[i][j2];
        }
        if(dp[i][j1][j2]!= -1) return dp[i][j1][j2];
        int sum= 0;
        for(int p= -1; p<2; p++){
            for(int q= -1; q<2; q++){
                int k= helper(i+1, j1+p, j2+q, dp, m, n, grid);
                if(k>sum) sum= k;
            }
        }
        if(j1==j2) return dp[i][j1][j2]= grid[i][j1]+ sum;
        return dp[i][j1][j2]= grid[i][j1]+ grid[i][j2]+ sum;
    }
};