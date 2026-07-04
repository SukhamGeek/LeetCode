class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        if(m<=2 || n<=2) return 0;
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int i=0; i<n; i++){
            if(grid[0][i]==1) dfs(0, i, vis, m, n, grid);
        }
        for(int i=0; i<n; i++){
            if(grid[m-1][i]==1) dfs(m-1, i, vis, m, n, grid);
        }
        for(int i=1; i<m-1; i++){
            if(grid[i][0]==1) dfs(i, 0, vis, m, n, grid);
            if(grid[i][n-1]==1) dfs(i, n-1, vis, m, n, grid);
        }
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(grid[i][j]==1 && vis[i][j]==0) ans++;
            }
        }
        return ans;
    }
    void dfs(int i, int j, vector<vector<int>>&vis, int m, int n, vector<vector<int>>& grid){
        if(i<0 || j<0 || i==m || j==n) return;
        if(grid[i][j]==0) return;
        if(vis[i][j]==1) return;
        vis[i][j]=1;
        dfs(i+1, j, vis, m, n, grid);
        dfs(i-1, j, vis, m, n, grid);
        dfs(i, j+1, vis, m, n, grid);
        dfs(i, j-1, vis, m, n, grid);
    }
};