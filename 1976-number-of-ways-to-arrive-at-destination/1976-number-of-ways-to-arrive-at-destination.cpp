class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        if(n==1) return 1;
        const int mod= 1e9+ 7;
        int ans=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        unordered_map<int,long long> mpp;
        mpp[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dis(n,LLONG_MAX);
        dis[0]= 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [dist,node]= pq.top();
            pq.pop();
            for(auto it: adj[node]){
                if((1LL*dist+ it.second)== dis[it.first]) mpp[it.first]=  (mpp[it.first]+ mpp[node])% mod;
                else if((1LL*dist+ it.second)< dis[it.first]){
                    dis[it.first]= 1LL*dist+ it.second;
                    pq.push({dis[it.first], it.first});
                    mpp[it.first]= mpp[node];
                }
            }
        }
        return mpp[n-1];
    }
};