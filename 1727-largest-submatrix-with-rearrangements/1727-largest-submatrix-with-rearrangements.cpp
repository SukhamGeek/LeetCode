class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m= matrix.size();
        int n= matrix[0].size();
        vector<int>arr(n,0);
        int h=0;
        for(int i=0; i<m; i++){
            int sum=0;
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    arr[j]++;
                }
                else{
                    arr[j]=0;
                }
            }
            vector<int> temp= arr;
            int freq=0;
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());
            for(int j=0; j<temp.size(); j++){
                freq++;
                int den= temp[j]*freq;
                if(den>sum) sum=den;
            }
            if(sum>h) h=sum;
        }
        return h;
    }
};