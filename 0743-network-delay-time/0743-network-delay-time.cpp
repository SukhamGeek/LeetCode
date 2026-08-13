class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans= 0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({k,0});
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        while(!pq.empty()){
            auto[node, dist]= pq.top();
            pq.pop();
            for(auto it: adj[node]){
                int a= it.first;
                int b= it.second;
                if((b+dist)<dis[a]){
                    dis[a]= b+dist;
                    pq.push({a, dis[a]});
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(dis[i]> ans) ans= dis[i];
        }
        if(ans== INT_MAX) return -1;
        return ans;
    }
};