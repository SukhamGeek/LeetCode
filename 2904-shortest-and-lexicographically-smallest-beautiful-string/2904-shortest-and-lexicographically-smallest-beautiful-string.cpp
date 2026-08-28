class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int n= s.size();
        int r=0;
        while(r<n && s[r]!='1'){
            r++;
        }
        int l=r;
        if(r==n) return ans;
        int c=0;
        int count=0;
        string temp="";
        while(r<n){
            if(s[r]=='1') count++;
            temp.push_back(s[r]);
            if(count==k){
                count--;
                if(ans.empty() || temp.size()<ans.size() || (temp.size()== ans.size()&& temp<ans)){
                    ans= temp;
                }
                l++;
                while(l<=r && s[l]!='1'){
                    l++;
                    c--;
                }
                temp= s.substr(l,c);
                r++;
                continue;
            }
            c++;
            r++;
        }
        return ans;
    }
};