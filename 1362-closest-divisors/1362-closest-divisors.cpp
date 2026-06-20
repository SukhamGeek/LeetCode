class Solution {
public:
    vector<int> closestDivisors(int num) {
        int a=num+1;
        int b= num+2;
        int mini=INT_MAX;
        vector<int>vec(2);
        for(int i=1; i<=sqrt(a); i++){
            if(a%i==0){
                int k= a/i;
                if(abs(i-k)<mini){
                    mini= abs(i-k);
                    vec[0]=i;
                    vec[1]=k;
                } 
            }
        }
        for(int i=1; i<=sqrt(b); i++){
            if(b%i==0){
                int k= b/i;
                if(abs(i-k)<mini){
                    mini= abs(i-k);
                    vec[0]=i;
                    vec[1]=k;
                } 
            }
        }   
        return vec;     
    }
};