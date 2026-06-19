class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        long long k= 1<<n;
        for(int i=0; i<k; i++){
            vector<int>temp;
            for(int j=0; j<n; j++){
                if((i&(1<<j))!=0){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};