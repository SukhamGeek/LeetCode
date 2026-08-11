class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m= heights.size();
        int n= heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(m, vector<int>(n,INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0]= 0;
        while(!pq.empty()){
            int dist= pq.top().first;
            int a= pq.top().second.first;
            int b= pq.top().second.second;
            pq.pop();
            if(a==m-1 && b==n-1) return dist;
            vector<int> r= {1,0,-1,0};
            vector<int> c= {0,1,0,-1};
            for(int i=0; i<4; i++){
                int nr= a+ r[i];
                int nc= b+ c[i];
                if(nr<m && nc<n && nr>=0 && nc>=0){
                    int newEffort= max(dist, abs(heights[a][b]- heights[nr][nc]));
                    if(newEffort< dis[nr][nc]){
                        dis[nr][nc]= newEffort;
                        pq.push({dis[nr][nc],{nr,nc}});
                    } 
                }

            }
        }
        return dis[m-1][n-1];
    }
};