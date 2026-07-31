class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> vis(m, vector<int>(grid[0].size(),-1));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    dfs(grid, vis, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int & m, int& n){
        if(i==m || j==n || i<0 || j<0) return;
        if(vis[i][j]!=-1) return;
        if(grid[i][j]=='0') return;
        vis[i][j]=1;
        dfs(grid, vis, i+1, j, m, n);
        dfs(grid, vis, i, j+1, m, n);
        dfs(grid, vis, i, j-1, m, n);
        dfs(grid, vis, i-1, j, m, n);
    }
};