class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int p= invocations.size();
        vector<int> res;
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        vector<bool> sus(n, false);
        vector<int> vis(n, -1);
        for(auto it: invocations){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        dfs(adj, k, vis, sus, in);
        bool flag= false;
        for(int i=0; i<n; i++){
            if(sus[i]==true && in[i]>0){
                flag= true;
                break;
            }
        }   
        if(flag){
            for(int i=0; i<n; i++){
                res.push_back(i);
            }
            return res;
        } 
        for(int i=0; i<n; i++){
            if(sus[i]==false) res.push_back(i);
        }
        return res;
    }
    void dfs(vector<vector<int>>& adj, int ind, vector<int>& vis, vector<bool>& sus, vector<int>& in){
        if(vis[ind]!= -1) return;
        vis[ind]= 1;
        sus[ind]= true;
        for(auto p: adj[ind]){
            in[p]--;
            dfs(adj, p, vis, sus, in);
        }
    }
};