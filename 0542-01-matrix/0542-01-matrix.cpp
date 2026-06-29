class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int s= q.size();
            for(int i=0; i<s; i++){
                auto[x,y]= q.front();
                q.pop();
                if(mat[x][y]==0){
                    dp[x][y]=0;
                }
                else{
                    int a= INT_MAX;
                    int b= INT_MAX;
                    int c=INT_MAX;
                    int d= INT_MAX;
                    if((x-1)>=0) a= dp[x-1][y];
                    if((y-1)>=0) b= dp[x][y-1];
                    if((x+1)<m) c= dp[x+1][y];
                    if((y+1)<n) d= dp[x][y+1];
                    dp[x][y]= min({a, b, c, d})+1;
                }
                if((x+1)<m&& vis[x+1][y]!=1){
                    q.push({x+1,y});
                    vis[x+1][y]=1;
                }
                if((x-1)>=0&& vis[x-1][y]!=1){
                    q.push({x-1,y});
                    vis[x-1][y]=1;
                }
                if((y+1)<n&& vis[x][y+1]!=1){
                    q.push({x,y+1});
                    vis[x][y+1]=1;
                }
                if((y-1)>=0&& vis[x][y-1]!=1){
                    q.push({x,y-1});
                    vis[x][y-1]=1;
                }
            }
        }
        return dp;
    }
};