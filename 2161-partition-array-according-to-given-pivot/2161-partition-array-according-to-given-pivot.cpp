class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less=0;
        int equal=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==pivot){
                equal++;
            }
            if(nums[i]<pivot) less++;
        }
        int check=0;
        vector<int>left(less);
        vector<int>right(n-(less+equal));
        int l=0;
        int r=0;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                left[l]=nums[i];
                l++;
            }
            else if(nums[i]>pivot){
                right[r]=nums[i];
                r++;
            }
            else{
                check++;
            }
        }
        for(int i=0; i<left.size(); i++){
            nums[i]=left[i];
        }
        int i=left.size();
        while(check>0){
            nums[i]=pivot;
            i++;
            check--;
        }
        
        for(int j=0; j<right.size(); j++){
            nums[i+j]=right[j];
        }
        return nums;
    }
};