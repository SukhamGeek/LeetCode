class Solution {
public:
vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec={1,2,3,4,5,6,7,8,9};
        vector<int>curr;
        int p= vec.size();
        helper(vec, 0,0, curr,n, p,k);
        return ans;
    }
    void helper(vector<int>& nums, int ind, int sum, vector<int>& curr, int n, int p, int k){
        if(sum==n&& curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(sum==n) return;
        if(ind>=p) return;
        for(int i=ind; i<nums.size(); i++){
            curr.push_back(nums[i]);
            helper(nums, i+1, sum+nums[i], curr, n, p, k);
            curr.pop_back();
        }
    }
};