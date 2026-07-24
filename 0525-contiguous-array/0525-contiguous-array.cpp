class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefix=0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) prefix++;
            else prefix--;
            if(mpp.find(prefix)!= mpp.end()){
                ans= max(ans, i-mpp[prefix]);
            }
            if(mpp.find(prefix)==mpp.end()) mpp[prefix]=i;
        }
        return ans;
    }
};