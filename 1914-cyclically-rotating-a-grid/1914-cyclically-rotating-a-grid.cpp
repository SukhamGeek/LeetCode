class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size(); 
        int n= grid[0].size();
        int p= (min(m,n))/2;
        for(int i=0; i<p; i++){
            vector<int> temp;
            int p= k%(2*(m+n-4*i)-4);
            for(int x=i; x<n-i; x++){
                temp.push_back(grid[i][x]);
            }
            for(int y=i+1; y<m-i; y++){
                temp.push_back(grid[y][n-i-1]);
            }
            for(int x=n-i-2; x>=i; x--){
                temp.push_back(grid[m-i-1][x]);
            }
            for(int y=m-i-2; y>i; y--){
                temp.push_back(grid[y][i]);
            }
            reverse(temp.begin(), temp.begin()+p);
            reverse(temp.begin()+p, temp.end());
            reverse(temp.begin(), temp.end());
            int j=0;
            for(int x=i; x<n-i; x++){
                grid[i][x]= temp[j];
                j++;
            }
            for(int y=i+1; y<m-i; y++){
                grid[y][n-i-1]= temp[j];
                j++;
            }
            for(int x=n-i-2; x>=i; x--){
                grid[m-i-1][x]= temp[j];
                j++;
            }
            for(int y=m-i-2; y>i; y--){
                grid[y][i]= temp[j];
                j++;
            }
        }
        return grid;
    }
};