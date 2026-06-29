class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>arr(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            arr[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>visited(numCourses,0);
        vector<int>pathvis(numCourses,0);
        for(int i=0; i<arr.size(); i++){
            if(visited[i]==0&& arr[i].size()!=0){
                bool b= helper(i, visited, arr, pathvis);
                if(b== false) return false;
            }
        }
        return true;
    }
    bool helper(int node, vector<int>& visited, vector<vector<int>>&arr, vector<int>& pathvis){
        if(visited[node]==1&& pathvis[node]==1) return false;
        else if(visited[node]==1) return true;
        visited[node]=1;
        pathvis[node]=1;
        for(auto it: arr[node]){
            bool b=helper(it, visited, arr, pathvis);
            if(!b) return false;
        }
        pathvis[node]=0;
        return true;
    }
};