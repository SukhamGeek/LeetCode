class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int res=0;
        bool b= false;
        int maxi= INT_MIN;
        for(auto it: nums){
            if(it>0){
                b=true;
                break;
            }
            maxi= max(maxi, it);
        }
        if(!b) return maxi;
        for(auto it: nums){
            sum+= it;
            if(it<0){
                res= max(res,sum-it);
            }
            if(sum<0) sum=0;
            cout<<res<<" "<<it<<endl;
        }
        res= max(res,sum);
        return res;
    }
};