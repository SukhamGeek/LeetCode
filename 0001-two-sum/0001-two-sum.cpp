class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> res(2);
        for(int i=0; i<nums.size(); i++){
            int rem= target- nums[i];
            if(mpp.find(rem)!=mpp.end()){
                res[0]= mpp[rem];
                res[1]= i;
                return res;
            }
            mpp[nums[i]]= i;
        }
        return res;
    }
};