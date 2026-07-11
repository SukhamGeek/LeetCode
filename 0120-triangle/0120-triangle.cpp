class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<int> dp(n);
        for(int i=0 ; i<n; i++){
            dp[i]= triangle[n-1][i];
        }
        int prev= n-1;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int d= triangle[i][j]+ dp[j];
                int d2= triangle[i][j]+ dp[j+1];
                dp[j]= min(d, d2);
            }
        }
        return dp[0];
    }
};