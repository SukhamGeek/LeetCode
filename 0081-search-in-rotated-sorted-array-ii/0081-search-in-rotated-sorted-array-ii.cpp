class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int mid= l+(h-l)/2;
        while(l<=h){
            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[l]&& nums[mid]==nums[h]){
                l++;
                h--;
            }
            else if(nums[mid]>=nums[l]){
                if(target<nums[mid]&& target>=nums[l]) h=mid-1;
                else l=mid+1;
            }
            else{
                if(target>nums[mid]&& target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
            mid= l+(h-l)/2;
        }
        return false;
    }
};