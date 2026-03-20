class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> vec(m-k+1, vector<int>(n-k+1,INT_MAX));
        if(k==1){
            vec.assign(m-k+1, vector<int>(n-k+1, 0));
        }
        for(int i=0; i<m-k+1; i++){
            for(int j=0; j<n-k+1; j++){
                vector<int> c;
                for(int p=i; p<i+k; p++){
                    for(int n=j; n<j+k; n++){
                        c.push_back(grid[p][n]);
                    }
                }
                sort(c.begin(),c.end());
                for(int p=0; p<c.size()-1; p++){
                    if((c[p+1]-c[p])<vec[i][j]&&(c[p+1]-c[p])!=0){
                        vec[i][j]= c[p+1]- c[p];
                    }
                }
                if(vec[i][j]==INT_MAX){
                    vec[i][j]=0;
                }
            }
        }
        return vec;
    }
};