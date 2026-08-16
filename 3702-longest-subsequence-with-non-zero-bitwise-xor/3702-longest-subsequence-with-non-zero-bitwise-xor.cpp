class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        bool b= false;
        for(auto it: nums){
            if(it!=0) b=true;
            ans^= it;
        }
        if(b && ans==0) return n-1;
        if(!b && ans==0) return 0;
        return n;
    }
};