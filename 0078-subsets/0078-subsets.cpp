class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<int> curr;
        helper(nums, 0, n, curr);
        return ans;
    }
    void helper(vector<int>& nums, int ind, int n, vector<int>& curr){
        if(ind>n) return;
        ans.push_back(curr);
        for(int i= ind; i<n; i++){
            curr.push_back(nums[i]);
            helper(nums, i+1, n, curr);
            curr.pop_back();
        }
    }
};