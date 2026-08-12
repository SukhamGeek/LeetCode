class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        queue<pair<int,int>> q;
        q.push({src, 0});
        int count=0;
        while(!q.empty() && count<=k){
            int s= q.size();
            for(int i=0; i<s; i++){
                auto[node,dis]= q.front();
                q.pop();
                for(int j=0; j<adj[node].size(); j++){
                    if((dis+ adj[node][j].second)< dist[adj[node][j].first]){
                        dist[adj[node][j].first]= dis+ adj[node][j].second;
                        q.push({adj[node][j].first, dist[adj[node][j].first]});
                    }
                }
            }
            count++;
        }
        if(dist[dst]== INT_MAX) return -1;
        return dist[dst];
    }
};