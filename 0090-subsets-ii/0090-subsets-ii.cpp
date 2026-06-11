class Solution {
public:
vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        helper(nums, 0, curr, n);
        return ans;
    }
    void helper(vector<int>& nums, int ind, vector<int>& curr, int& n){
        ans.push_back(curr);
        if(ind>=n) return;
        for(int i=ind; i<n; i++){
            if(i>ind&&nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            helper(nums, i+1, curr, n);
            curr.pop_back();
        }
    }
};