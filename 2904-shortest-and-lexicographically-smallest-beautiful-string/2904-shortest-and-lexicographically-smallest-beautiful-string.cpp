class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.size();
        vector<vector<string>> res(n+1);
        for(int i=0; i<n; i++){
            string temp="";
            int count=0;
            for(int j=i; j<n; j++){
                if(s[j]=='1'){
                    count++;
                } 
                if(count>0) temp.push_back(s[j]);
                if(count==k){
                    int a= temp.size();
                    res[a].push_back(temp);
                    break;
                } 
            }
        }
        for(int i=0; i<=n; i++){
            if(res[i].size()>0){
                sort(res[i].begin(), res[i].end());
                return res[i][0];
            }
        }
        return "";
    }
};