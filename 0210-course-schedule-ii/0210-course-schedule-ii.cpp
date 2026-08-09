class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
        vector<vector<int>> adj(numCourses);
        vector<int> ino(numCourses,0);
        queue<int>q;
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            ino[it[0]]++;
        }
        for(int i=0; i<numCourses; i++){
            if(ino[i]==0) q.push(i);
        }
        while(!q.empty()){
            int k= q.front();
            res.push_back(k);
            q.pop();
            for(auto it: adj[k]){
                ino[it]--;
                if(ino[it]==0)q.push(it);
            }
        }
        if(res.size()!=numCourses) res.clear(); 
        return res;
    }
};