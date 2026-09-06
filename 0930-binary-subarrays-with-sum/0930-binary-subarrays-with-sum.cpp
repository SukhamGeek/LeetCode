class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans= atmost(goal, nums)- atmost(goal-1, nums);
        return ans;
    }
    int atmost(int goal, vector<int>& nums){
        if(goal<0) return 0;
        int count=0;
        int l=0; int r=0;
        int pre=0; int n= nums.size();
        while(r<n){
            pre+= nums[r];
            if(pre> goal){
                while(l<=r && pre > goal){
                    pre-= nums[l];
                    l++;
                }
            }
            count+= r-l+1;
            cout<<count<<"-"<<r<<endl;
            r++;
        }
        return count;
    }
};