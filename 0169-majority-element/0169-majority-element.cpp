class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        int check=1;
        int ans= nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==ans) check++;
            else{
                if(check<=1){
                    check=1;
                    ans= nums[i];
                }
                else check--;
            }
        }
        return ans;
    }
};