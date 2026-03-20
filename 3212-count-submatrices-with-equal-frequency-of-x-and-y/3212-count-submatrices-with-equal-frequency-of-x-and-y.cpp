class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0; i<m; i++){
            int X=0;
            int Y=0;
            for(int j=0; j<n; j++){
                if(grid[i][j]=='X'){
                    x[j]++;
                }
                else if(grid[i][j]=='Y'){
                    y[j]++;
                }
            }
            for(int j=0; j<n; j++){
                if((X+x[j])==(Y+y[j])&& (X+x[j])>0){
                    ans++;
                }  
                X+=x[j];
                Y+=y[j];    
            }

        }
        return ans;
    }
};