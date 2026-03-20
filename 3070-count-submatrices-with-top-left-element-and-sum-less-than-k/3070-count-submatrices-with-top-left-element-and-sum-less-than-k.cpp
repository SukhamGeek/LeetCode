class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
         int n= grid[0].size();
        vector<int>arr(n,0); 
        int m= grid.size();
        int ans=0;
        for(int i=0; i<m ;i++){
            int ps=0;
            for(int j=0; j<n; j++){
                int sum= grid[i][j]+ arr[j]+ps;
                if(sum<=k){
                    ans++;
                }  
                arr[j]+= grid[i][j]; 
                ps= sum;         
            }
        }
    return ans;
    }
};