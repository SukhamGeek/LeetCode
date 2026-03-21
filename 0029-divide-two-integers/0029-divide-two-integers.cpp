class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a= (long long)dividend/divisor;
        if(a>INT_MAX) return INT_MAX;
        if(a<INT_MIN) return INT_MIN;
        int b= a;
        return b;
    }
};