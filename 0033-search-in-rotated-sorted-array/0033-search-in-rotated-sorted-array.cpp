class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid= rot(nums);
        cout<<mid;
        if(mid==-1){
            mid= nums.size()/2;
        }
        int l1=0;
        int h1=mid-1;
        int l2= mid;
        int h2= nums.size()-1;
        int m1= l1+(h1-l1)/2;
        int m2= l2+(h2-l2)/2;
        while(l1<=h1){
            if(nums[m1]==target) return m1;
            else if(nums[m1]<target) l1= m1+1;
            else h1= m1-1;
            m1= l1+(h1-l1)/2;
        }
        while(l2<=h2){
            if(nums[m2]==target) return m2;
            else if(nums[m2]<target) l2= m2+1;
            else h2= m2-1;
            m2= l2+(h2-l2)/2;
        }
        return -1;
    }
    int rot(vector<int>& nums) {
    int l = 0;
    int h = nums.size() - 1;

    // already sorted, no rotation
    if(nums[l] <= nums[h]) return 0;

    while(l <= h) {
        int mid = l + (h - l) / 2;

        // pivot found
        if(mid < nums.size()-1 && nums[mid] > nums[mid+1])
            return mid + 1;

        if(nums[mid] >= nums[l])
            l = mid + 1;
        else
            h = mid - 1;
    }

    return 0;
}
};