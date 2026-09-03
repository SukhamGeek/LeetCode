class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int n= s.size();
        int ans=0;
        if(k==0){
            int c=1;
            for(int i=1; i<n; i++){
                if(s[i]!=s[i-1]){
                    ans= max(ans,c);
                    c=1;
                    continue;
                }
                c++;
            }
            ans= max(ans, c);
            return ans;
        }
        int r=0;
        int l=0;
        int cons=0;
        while(r<n){
           count[s[r]-'A']++; 
           int c=0; 
           for(int i=0; i<26; i++){
                if(count[i]>c) c=count[i];
           }
           if((c+k)<(r-l+1)){
                count[s[l]-'A']--;
                l++;
                
           }
           ans= max(ans, r-l+1);
           r++;
        }
        return ans;
    }
};