class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n,vector<int>(n, -2)));
        int ans= h1(0, 0, 0, 0, grid, n, dp );
        if(ans<0) return 0;
        return ans;
    }
    int h1(int i1, int j1, int i2, int k, vector<vector<int>>& grid, int& n, vector<vector<vector<int>>>& dp){
        if(i1==n || j1==n || i2==n || (i1+j1-i2)==n ) return INT_MIN;
        if(grid[i1][j1]==-1 || grid[i2][(i1+j1-i2)]== -1) return INT_MIN;
        if(i1==n-1 && j1==n-1 && i2==n-1 && (i1+j1-i2)==n-1){
            return grid[i1][j1];
        }
        if(dp[i1][i2][j1]!= -2) return dp[i1][i2][j1];
        int rl= h1(i1, j1+1, i2, k+1, grid, n, dp);
        int ru= h1(i1, j1+1, i2+1, k+1, grid, n, dp);
        int dl= h1(i1+1, j1, i2, k+1, grid, n, dp);
        int du= h1(i1+1, j1, i2+1, k+1, grid, n, dp);
        if(i1==i2 && j1==(i1+j1-i2)) return dp[i1][i2][j1]= grid[i1][j1]+ max({rl,ru,dl,du});
        return dp[i1][i2][j1]= grid[i1][j1]+ grid[i2][(i1+j1-i2)]+max({rl,ru,dl,du});
    }
};