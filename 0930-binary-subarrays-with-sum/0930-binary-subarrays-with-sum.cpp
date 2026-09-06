class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int n= nums.size();
        unordered_map<int,int> pref;
        int presum=0;
        pref[0]++;
        for(int i=0; i<n; i++){
            presum+= nums[i];
            if(pref.find(presum-goal)!= pref.end()){
                ans+= pref[presum-goal];
            }
            pref[presum]++;
        }
        return ans;
    }
};