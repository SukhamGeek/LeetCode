class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> mpp;
        unordered_map<char,char>flag;
        int check=0;
        for(int i=0; i<s.size();i++){
            mpp[s[i]]++;
            if(mpp[s[i]]==1){
                if(flag.find(t[i])==flag.end()){
                    flag[t[i]]=s[i];
                }
                else{
                   return false;
                }
            }
            else if(flag[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};