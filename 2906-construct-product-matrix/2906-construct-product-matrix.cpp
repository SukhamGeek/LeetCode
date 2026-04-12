class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int> arr;
        const int mod= 12345;
        int m= grid.size();
        int n= grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                arr.push_back(grid[i][j]%12345);
            }
        }
        
        vector<int> suff(arr.size());
        vector<int> pre(arr.size());
        suff[0]=1;
        pre[arr.size()-1]=1;
        for(int i=1; i<arr.size(); i++){
            suff[i]= (suff[i-1]*arr[i-1])%mod;
        }
        for(int i= arr.size()-2; i>=0; i--){
            pre[i]= (pre[i+1]*arr[i+1])%mod;
        }
        int k=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j]= (suff[k]*pre[k])%mod;
                k++;
            }
        }
        return grid;
    }
};