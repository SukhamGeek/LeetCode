
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        int ans=0;
        map<pair<int,int>, vector<pair<int,int>>> mpp;
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                mpp[{points[i][0],points[i][1]}].push_back({points[j][0],points[j][1]});
                mpp[{points[j][0],points[j][1]}].push_back({points[i][0],points[i][1]});
            }
        }
        map<pair<int,int>, int> vis;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{points[0][0],points[0][1]}});
        while(!pq.empty()){
            auto[dis, coor]= pq.top();
            pq.pop();
            if(vis.find(coor)!=vis.end())continue;
            ans+= dis;
            vis[coor]=1;
            for(auto it: mpp[coor]){
                if(vis.find(it)!=vis.end()) continue;
                int dist= abs(coor.first- it.first)+ abs(coor.second - it.second);
                pq.push({dist,it});
            }
        }
        return ans;
    }
};