class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        int count=0;
        vector<bool>prime(1000,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2; i*i<1000;i++){
            if(prime[i]){
                for(int j=i*i; j<1000; j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<int> arr;
        for(int i=0; i<1000; i++){
            if(prime[i]){
                arr.push_back(i);
            }
        }
        for(auto it:nums){
            int k=0;
            while(it>1){
                while(it%arr[k]==0){
                    st.insert(arr[k]);
                    it/=arr[k];
                }
                k++;
            }
        }
        return st.size();
    }
};