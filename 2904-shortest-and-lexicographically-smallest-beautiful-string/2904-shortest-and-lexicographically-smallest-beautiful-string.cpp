class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<vector<string>> res(s.size()+1);
        int n= s.size();
        int r=0;
        while(r<n && s[r]!='1'){
            r++;
        }
        int l=r;
        if(r==n) return "";
        int c=0;
        int count=0;
        string temp="";
        while(r<n){
            if(s[r]=='1') count++;
            temp.push_back(s[r]);
            if(count==k){
                count--;
                res[temp.size()].push_back(temp);
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
        for(auto it: res){
            if(it.size()>0){
                sort(it.begin(), it.end());
                return it[0];
            }
        }
        return "";
    }
};