class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n= s.size();
        return helper(s, 0, st, n, 0, "", dp);
    }
    bool helper(string& s, int ind, unordered_set<string>& st, int& n, int count, string temp,vector<vector<int>>&dp){
        if(ind==n&&st.count(temp)){
            return true;
        }
        if(ind>=n) return false;
        if(dp[ind][count]!=-1){
            if(dp[ind][count]==1) return true;
            return false;
        }
        temp.push_back(s[ind]);
        count++;
        bool k=helper(s, ind+1, st, n,count, temp, dp);
        count--;
        if(k){
            dp[ind][count]=1;
            return true;
        }
        temp.pop_back();
        if(st.count(temp)){
            temp.clear();
            bool k2=helper(s, ind+1, st, n, 1, temp+s[ind], dp);
        if(k2){
            dp[ind][count]=1;
            return true;
        }
        }
        dp[ind][count]=0;
        return false;
    }
};