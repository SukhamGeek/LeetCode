class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int ans=0;
        int l=0;
        int count=0;
        int c0=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1) count++;
            else{
                c0++;
                if(c0>k){
                    ans=max(ans, count);
                    while(nums[l]!=0){
                        l++;
                    }
                    l++;
                    count= i-l+1;
                    c0--;
                }
                else count++;
            }
        }
        ans= max(ans,count);
        return ans;
    }
};