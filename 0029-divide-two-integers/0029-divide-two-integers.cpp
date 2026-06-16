class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        if(dividend==0) return 0;
        long long temp= (1LL)*abs(1LL*dividend);
        long long q=0;
        long long d= 1LL*abs(1LL*divisor);
        while(temp>=d){
            long long i=1;
            long long k=i;
            while(d*i<=temp){
                k=i;
                i<<=1;
            }
            q+=k;
            temp-=d*k;
        }
        if((dividend>0&&divisor>0)||(dividend<0&&divisor<0)) return q;
        return -q;
    }
};