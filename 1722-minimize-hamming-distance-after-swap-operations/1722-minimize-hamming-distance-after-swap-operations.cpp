class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);   // path compression
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        // union by size
        if (sz[x] < sz[y])
            swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
    }

    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        parent.resize(n);
        sz.resize(n, 1);

        // initially every index is its own component
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // make connected components of indices
        for (auto &edge : allowedSwaps) {
            unionSet(edge[0], edge[1]);
        }

        // For each component, store frequency of source values
        unordered_map<int, unordered_map<int, int>> freq;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            freq[root][source[i]]++;
        }

        int ans = 0;

        // Try to satisfy each target value from same component
        for (int i = 0; i < n; i++) {
            int root = find(i);

            if (freq[root][target[i]] > 0) {
                freq[root][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};