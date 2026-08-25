class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int ans=0;
        int count=0;
        int l=0; 
        unordered_map<char,int> mpp;
        for(int i=0; i<s.size(); i++){
            if(mpp.find(s[i])==mpp.end()){
                count++;
                mpp[s[i]]=i;
            } 
            else{
                ans= max(ans,count);
                l= max(l,mpp[s[i]]+1);
                count= i-l+1;
                mpp[s[i]]=i;
            }
        }
        ans= max(ans,count);
        return ans;
    }
};