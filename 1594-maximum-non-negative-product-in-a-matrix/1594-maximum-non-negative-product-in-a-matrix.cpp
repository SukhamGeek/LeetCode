class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MIN));   // max
        vector<vector<long long>> dp2(m, vector<long long>(n, LLONG_MAX));  // min

        helper(grid, 0, 0, m, n, dp, dp2);

        long long ans = dp[0][0];
        if(ans < 0) return -1;

        return ans % 1000000007;
    }

    void helper(vector<vector<int>>& grid, int x, int y, int m, int n,
                vector<vector<long long>>& dp,
                vector<vector<long long>>& dp2) {

        if(dp[x][y] != LLONG_MIN) return;

        if(x == m-1 && y == n-1) {
            dp[x][y] = grid[x][y];
            dp2[x][y] = grid[x][y];
            return;
        }

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

       
        if(x < m-1) {
            helper(grid, x+1, y, m, n, dp, dp2);

            long long a = grid[x][y] * dp[x+1][y];
            long long b = grid[x][y] * dp2[x+1][y];

            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }

        if(y < n-1) {
            helper(grid, x, y+1, m, n, dp, dp2);

            long long a = grid[x][y] * dp[x][y+1];
            long long b = grid[x][y] * dp2[x][y+1];

            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }

        dp[x][y] = maxi;
        dp2[x][y] = mini;
    }
};