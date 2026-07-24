class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix=0;
        int ans=0;
        unordered_map<int, int> mpp;
        mpp[0]++;
        for(auto it: nums){
            prefix+= it;
            if(mpp.find(prefix-k)!=mpp.end()){
                ans+= mpp[prefix-k];
            }
            mpp[prefix]++;
        }
        return ans;
    }
};