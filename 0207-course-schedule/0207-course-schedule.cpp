class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        queue<int>q;
        vector<int> ind(numCourses,0);
        int count=0;
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        for(int i=0; i<ind.size(); i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int k= q.front();
            count++;
            q.pop();
            for(auto it: adj[k]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};