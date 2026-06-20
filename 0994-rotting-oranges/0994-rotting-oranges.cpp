class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int count=0;
        int m= grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) count++;
            }
        }
        if(count==0) return 0;
        int flag=0;
        while(!q.empty()){
            int s= q.size();
            for(int i=0; i<s; i++){
                auto[a,b]= q.front();
                q.pop();
                if((a+1)<m&& grid[a+1][b]==1){
                    grid[a+1][b]=2;
                    q.push({a+1,b});
                    count--;
                } 
                if((b+1)<n &&grid[a][b+1]==1){
                    grid[a][b+1]=2;
                    q.push({a,b+1});
                    count--;
                } 
                if((a-1)>=0 &&grid[a-1][b]==1){
                    grid[a-1][b]=2;
                   q.push({a-1,b});
                   count--;
                }
                if((b-1)>=0 &&grid[a][b-1]==1){
                    grid[a][b-1]=2;
                    q.push({a,b-1});
                    count--;
                } 
            }
            flag++;
        }
        if(count!=0) return -1;
        return flag-1;
    }
};