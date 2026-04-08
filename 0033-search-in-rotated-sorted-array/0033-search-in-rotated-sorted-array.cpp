class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h= nums.size()-1;
        int mid= l+(h-l)/2;
        while(l<=h){
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){//left side is sorted check
                if(target>=nums[l]&&target<nums[mid]) h=mid-1;
                else l=mid+1;
            }
            else{//If left not sorted we move to the right side for the check
                if(target>nums[mid]&&target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
            mid= l+(h-l)/2;
        }
        return -1;
        //We are sure that atleast one of the left or right side is sorted in a scenario so we use it
    }
};