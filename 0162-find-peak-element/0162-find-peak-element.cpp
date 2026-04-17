class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size()-1;
        if(n==0||nums[0]>nums[1]) return 0;
        if(nums[n]>nums[n-1]) return n;
        int l=1;
        int h= n-1;
        int mid= l+(h-l)/2;
        while(l<=h){
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
            if(nums[mid-1]>nums[mid]) h=mid-1;
            else l=mid+1;
            mid= l+(h-l)/2;
        }
        return -1;
    }
};