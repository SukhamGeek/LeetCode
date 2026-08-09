class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> ans;
        vector<int> ino(n,0);
        vector<vector<int>> adj(n);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for(int u = 0; u < n; u++) {
            for(int v : graph[u]) {
                adj[v].push_back(u);
            }
        }
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                ino[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(ino[i]==0) q.push(i);
        }
        while(!q.empty()){
            int k= q.front();
            ans.push_back(k);
            q.pop();
            for(auto it: adj[k]){
                ino[it]--;
                if(ino[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};