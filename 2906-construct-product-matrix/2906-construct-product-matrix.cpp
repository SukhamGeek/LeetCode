class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> suff(m, vector<int>(n));
        int prod = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                suff[i][j] = prod;
                prod = (1LL * prod * grid[i][j]) % mod;
            }
        }

        prod = 1;

        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur = grid[i][j];
                grid[i][j] = (1LL * prod * suff[i][j]) % mod;
                prod = (1LL * prod * cur) % mod;
            }
        }

        return grid;
    }
};