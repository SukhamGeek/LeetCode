class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<32; i++){
            int count=0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j]&1<<i) count++;
            }
            if(count%3==1) sum+= 1<<i;
        }     
        return sum;  
    }
};