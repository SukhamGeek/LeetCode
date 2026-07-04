class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        if(m<=2 || n<=2) return;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0; i<n; i++){
            if(board[0][i]=='O'){
                dfs(0,i, board, vis, m , n);
            }
        }
        for(int i=0; i<n; i++){
            if(board[m-1][i]=='O'){
                dfs(m-1,i, board, vis, m , n);
            }
        }
        for(int i=1; i<m-1; i++){
            if(board[i][0]=='O'){
                dfs(i,0, board, vis, m , n);
            }
            if(board[i][n-1]=='O'){
                dfs(i,n-1, board, vis, m , n);
            }
        }
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(board[i][j]=='O'&& vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, int m, int n){
        if(i<0 || j<0 || i==m || j==n) return;
        if(vis[i][j]==1) return;
        if(board[i][j]=='X') return;
        vis[i][j]=1;
        dfs(i+1, j, board, vis, m, n);
        dfs(i-1, j, board, vis, m, n);
        dfs(i, j+1, board, vis, m, n);
        dfs(i, j-1, board, vis, m, n);
    }
};