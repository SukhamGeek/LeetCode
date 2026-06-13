class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int p=0;
        int n= nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==pivot){
                p=i;
                break;
            }
        }
        int check=0;
        vector<int>left;
        vector<int>right;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                left.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                right.push_back(nums[i]);
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