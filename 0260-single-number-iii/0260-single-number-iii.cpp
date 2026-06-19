class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans^= nums[i];
        }
        long long p= 1LL*ans& ~(1LL*ans-1);
        ans=0;
        int b=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&p) ans^=nums[i];
            else{
                b^=nums[i];
            }
        }
        vector<int> vec={ans,b};
        return vec;
    }
};