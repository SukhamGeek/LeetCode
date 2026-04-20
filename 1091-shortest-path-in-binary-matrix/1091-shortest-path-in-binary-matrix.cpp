class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Edge Case: Start or end blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        // Edge Case: 1x1 matrix (The one your code currently misses)
        if (n == 1) return 1;

        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1}};
        
        q.push({0,0});
        grid[0][0] = 1; // Mark visited immediately on push
        int length = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();

                for(auto& it : dir){
                    int nx = x + it.first;
                    int ny = y + it.second;

                    // Bound check
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                        // Check if this neighbor is the target
                        if(nx == n-1 && ny == n-1) return length + 1;
                        
                        grid[nx][ny] = 1; // Mark visited
                        q.push({nx, ny});
                    }
                }
            }
            length++;
        }
        return -1;
    }
};