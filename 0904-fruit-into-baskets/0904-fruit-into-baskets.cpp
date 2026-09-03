class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        if(n<=2) return n;
        int ans=0;
        int r=1;
        int c1=0; int c2=1;
        int e2= fruits[0];
        int e1= INT_MIN;;
        while(r<n){
            if(fruits[r]==e2){
                c2++;
            }
            else if(e1!=INT_MIN && fruits[r]==e1) c1++;
            else{
                ans= max(ans, c1+c2);
                e1=fruits[r-1];
                c1=1;
                int move= r-2;
                while(move>=0 && fruits[move]==e1){
                    c1++;
                    move--;
                }
                e2= fruits[r];
                c2=1;

            }
            r++;
        }
        ans= max(ans, c1+c2);
        return ans;
    }
};