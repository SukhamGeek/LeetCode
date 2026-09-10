class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min=INT_MAX;
        for(int i=0; i<strs.size();i++){
            if(strs[i].size()<min){
                min= strs[i].size();
            }
        }
        if(min==0){
            return "";
        }
        string ans="";
        for(int i=0; i<min; i++){
            char c= strs[0][i];
            for(int j=1; j<strs.size();j++){
                if(strs[j][i]!=c){
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};