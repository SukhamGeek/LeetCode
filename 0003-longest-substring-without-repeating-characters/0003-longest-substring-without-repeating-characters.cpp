class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        unordered_set<char> st;
        int ans=0;
        int count=0;
        int l=0; int r=0;
        unordered_map<char,int> mpp;
        for(int i=0; i<s.size(); i++){
            if(!st.count(s[i])){
                st.insert(s[i]);
                count++;
                mpp[s[i]]=i;
            } 
            else{
                ans= max(ans,count);
                l= max(l,mpp[s[i]]+1);
                count= r-l+1;
                mpp[s[i]]=i;
            }
            r++;
        }
        ans= max(ans,count);
        return ans;
    }
};