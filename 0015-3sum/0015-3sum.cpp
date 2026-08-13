class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int tar= -nums[i];
            int l= i+1;
            int r= n-1;
            unordered_map<int,int> mpp;    
            while(l<r){
                int sum= nums[i]+nums[l]+ nums[r];
                if(sum<0) l++;
                else if(sum>0) r--;
                else{
                    vector<int> temp(3);
                    temp[0]= nums[i];
                    temp[1]= nums[l];
                    temp[2]= nums[r];
                    res.push_back(temp);
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                    l++;
                    }
                    while(l<r && nums[r]== nums[r+1]){
                        r--;
                    }
                }
            }
        }
        return res;
    }
};