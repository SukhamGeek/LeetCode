class Solution {
public:
vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        int n= s.size();
        vector<string>vec;
        string p;
        helper(s, 0, vec, n, p);
        return ans;
    }
    bool isPalindrome(string p){
        int i=0;
        int j= p.size()-1;
        bool check= false;
        while(i<=j){
            if(p[i]!=p[j]){
                check= true;
                break;
            }
            i++;
            j--;
        }
        if(check==true) return false;
        return true;
    }
    void helper(string& s, int ind, vector<string>& vec, int n, string curr){
        if(ind==n){
            if(isPalindrome(curr)){
                vec.push_back(curr);
                ans.push_back(vec);
                vec.pop_back();
            }
            return;
        }
        if(ind>n) return;
        helper(s, ind+1, vec, n, curr+s[ind]);
        if(curr.size()>0&&isPalindrome(curr)){
            vec.push_back(curr);
            curr.clear();
            helper(s, ind+1, vec, n, curr+s[ind]);
            vec.pop_back();
        } 
    }
};