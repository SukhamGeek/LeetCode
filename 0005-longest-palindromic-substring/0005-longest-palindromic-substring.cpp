class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        string ans="";
        ans+=s[0];
        for(int i=1; i<n; i++){
            int st=i-1;
            int e=i+1;
            while(st>=0 && e<n){
                if(s[st]!=s[e]){
                    break;
                }
                st--;
                e++;
            }
            if((e-st-1)>ans.size()){
                ans= s.substr(st+1,e-st-1);
            }
            st=i-1;
            e=i;
            while(st>=0 && e<n){
                if(s[st]!=s[e]){
                    break;
                }
                st--;
                e++;
            }
            if((e-st-1)>ans.size()){
                ans= s.substr(st+1,e-st-1);
            }
        }
        return ans;
    }
};