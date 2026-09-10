class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int open=0;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='(') open++;
            else open--;
            if(open>=0){
                ans.push_back(s[i]);
            } 
            else{
                open=0;
                i++;
            }
        }
        return ans;
    }
};