class Solution {
public:
vector<string> ans;
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>mpp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        string s;
        helper(mpp, digits, 0, s);
        return ans;
    }
    void helper(unordered_map<int,string>&mpp, string& digits, int ind, string& s){
        if(ind==(digits.size())){
            ans.push_back(s);
            return;
        }
        string temp= mpp[digits[ind]-'0'];
        for(int i=0; i<temp.size(); i++){
            s.push_back(temp[i]);
            helper(mpp, digits, ind+1,s);
            s.pop_back();
        }
    }
};