class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            if(product(n)%t==0) return n;
            n++;
        }
    }
    int product(int n){
        int prod= 1;
        while(n>0){
            prod*= n%10;
            n/=10;
        }
        return prod;
    }
};