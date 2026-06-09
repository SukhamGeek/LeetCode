class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
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
        curr.push_back(cand[ind]);
        helper(cand, ind, tar, sum+cand[ind],curr, n);
        curr.pop_back();
        helper(cand, ind+1, tar, sum, curr, n);
    }
};