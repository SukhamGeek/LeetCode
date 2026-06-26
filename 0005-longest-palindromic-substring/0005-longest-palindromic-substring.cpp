class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        string ans="";
        ans+=s[0];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                bool b=false;
                int m=i; 
                int n=j;
                while(m<n){
                    if(s[m]!= s[n]){
                        b=true;
                        break;
                    }
                    m++;
                    n--;
                }
                if(b) continue;
                else{
                    if((j-i+1)>ans.size()){
                        ans= s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};