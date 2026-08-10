class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> qu;
        vector<vector<int>> vis(n, vector<int>(n,-1));
        qu.push({0,0});
        vis[0][0]=1;
        int ans=0;
        bool b=false;
        while(!qu.empty()){
            int s= qu.size();
            for(int i=0; i<s; i++){
                auto[p,q]= qu.front();
                qu.pop();
                if(p==n-1 && q==n-1){
                    return ans+1;
                } 
                for(int l=-1; l<2; l++){
                    for(int r=-1; r<2; r++){
                        if(p+l>=0 && p+l<n && q+r>=0 && q+r<n && vis[p+l][q+r]==-1 && grid[p+l][q+r]==0 ){
                            qu.push({p+l, q+r});
                            vis[p+l][q+r]=1;
                        }
                    }
                } 
            }
            ans++;
        }
        return -1;
    }
};