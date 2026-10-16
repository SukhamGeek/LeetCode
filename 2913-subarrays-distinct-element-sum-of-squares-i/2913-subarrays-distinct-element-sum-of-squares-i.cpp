class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                st.insert(nums[j]);
                sum+= st.size()*st.size();
            }
            st.clear();
        }
        return sum;
    }
};