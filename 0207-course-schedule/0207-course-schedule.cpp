class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        queue<int>q;
        vector<int> ind(numCourses,0);
        vector<int>res;
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        bool b= false;
        for(int i=0; i<ind.size(); i++){
            if(ind[i]==0){
                q.push(i);
                b=true;
            } 
        }
        if(!b) return false;
        while(!q.empty()){
            int k= q.front();
            res.push_back(k);
            q.pop();
            for(auto it: adj[k]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        if(res.size()==numCourses) return true;
        return false;
    }
};