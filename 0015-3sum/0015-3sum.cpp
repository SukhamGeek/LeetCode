class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int tar= -nums[i];
            unordered_map<int,int> mpp;
            int sum=0;
            for(int j=i+1; j<n; j++){
                if(mpp.find(tar- nums[j])!=mpp.end()){
                    vector<int> temp(3);
                    temp[0]=nums[i];
                    temp[1]= nums[mpp[tar-nums[j]]];
                    temp[2]=nums[j];  
                     st.insert(temp); 
                }
                mpp[nums[j]]=j;
            }
        }
        for(auto it: st){
            res.push_back(it);
        }
        return res;
    }
};