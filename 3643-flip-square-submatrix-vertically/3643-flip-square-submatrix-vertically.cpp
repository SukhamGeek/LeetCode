class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        if(k==1){
            return grid;
        }
        int p=0;
        for(int i=x; i<x+(k/2); i++){
            for(int j=y; j<(y+k); j++){
                
                swap(grid[i][j],grid[i+k-1-2*p][j]);
            }
            p++;
        }
        return grid;
    }
};