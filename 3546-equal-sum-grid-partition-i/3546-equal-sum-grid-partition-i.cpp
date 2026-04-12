class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int ts=0;
        long long total=0;
        int m=grid.size();
        int n= grid[0].size();
        vector<long long> presum(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total+= grid[i][j];
                presum[j]+= grid[i][j];
            }
        }
        long long temp=0;
        for(int i=0; i<presum.size(); i++){
            temp+= presum[i];
            if(temp==(total-temp)) return true;
        }
        for(int i=0; i<m; i++){
            long long sum=0;
            for(int j=0; j<n; j++){
                sum+= grid[i][j];
            }
            ts+=sum;
            if(ts== total-ts) return true;
        }
        return false;
    }
};