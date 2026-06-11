class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum=0;
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        int n= candidates.size();
        helper(candidates, 0, target, 0, curr, n);
        return ans;
    }
       void helper(vector<int>&cand, int ind, int tar, int sum, vector<int>&curr, int n){
        if(sum>tar) return;
        if(sum==tar){
            ans.push_back(curr);
            return;
        }
        if(ind>=n) return;
        for(int i= ind; i<n; i++){
            if(i>ind&&cand[i]==cand[i-1]) continue;
            curr.push_back(cand[i]);
            helper(cand, i+1, tar, sum+cand[i], curr,n);
            curr.pop_back();
        }
    }
};