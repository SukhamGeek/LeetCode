class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxi=0;
        unordered_map<int,int> mpp;
        mpp[n-1]= -1;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && prices[i]>=prices[st.top()]){
                st.pop();
            }
            if(st.empty()){
                mpp[i]= -1;
            }
            else if(mpp[st.top()]== -1){
                mpp[i]= st.top();
            }
            else{
                mpp[i]= mpp[st.top()];
            }
            st.push(i);
            if(mpp[i]!= -1){
                maxi= max(maxi, prices[mpp[i]]-prices[i]);
            }
        }
        return maxi;
    }
};