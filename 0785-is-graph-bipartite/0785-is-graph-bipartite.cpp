class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>> adj(n);
        vector<int> color(n,-1);
        bool b=false;
        for(int i=0; i<n; i++){
            if(color[i]== -1){
                b= dfs(color, i, 0, graph);
            }
            if(!b) return false;
        }
        return true;
    }
    bool dfs(vector<int>& color, int ind, int col, vector<vector<int>>&graph){
        color[ind]= col;
        for(auto it: graph[ind]){
            if(color[it]!= -1){
                if(color[it]== color[ind]) return false;
                continue;
            }
            bool b= false;
            if(color[ind]==0) b= dfs(color, it, 1, graph);
            else if(color[ind]==1) b= dfs(color, it, 0, graph);
            if(b==false) return false;
        }
        return true;
    }

};