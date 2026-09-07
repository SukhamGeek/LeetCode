class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans= atmost(k, nums)- atmost(k-1, nums);
        return ans;
    }
    int atmost(int num, vector<int>& nums){
        if(num<0) return 0;
        int ans=0;
        int count=0; 
        int r=0;
        int l=0;
        while(r< nums.size()){
            if((nums[r])%2!=0) count++;
            if(count>num){
                count--;
                while(nums[l]%2 ==0){
                    l++;
                }
                l++;
            }
            ans+= r-l+1;
            r++;
        }
        cout<<num<<"-"<<ans<<endl;
        return ans;
    }
};