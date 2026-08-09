class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> ans;
        vector<int> ino(n,0);
        vector<int> safe(n,0);
        vector<vector<int>> adj(n);
        for(int u = 0; u < n; u++) {
            for(int v : graph[u]) {
                adj[v].push_back(u);
                ino[u]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(ino[i]==0) q.push(i);
        }
        while(!q.empty()){
            int k= q.front();
            safe[k]++;
            q.pop();
            for(auto it: adj[k]){
                ino[it]--;
                if(ino[it]==0) q.push(it);
            }
        }
        for(int i=0; i<n; i++){
            if(safe[i]==1) ans.push_back(i);
        }
  
        return ans;
    }
};