class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        vector<int>res;
        if(n==1){
            res.push_back(nums[0]);
            return res;
        }
        int k= (n/3)+1;
        sort(nums.begin(), nums.end());
        int count=1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]) count++;
            else{
                if(count>=k) res.push_back(nums[i-1]);
                count=1;
            }
        }
        if(count>=k) res.push_back(nums[n-1]);
        return res;
    }
};