class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans="";
        int n= s.size();
        vector<int> freq(26,0);
        for(auto it: s){
            freq[it-'a']++;
        }
        bool check= false;
        for(int i=0; i<n; i++){
            int x= target[i]-'a';
            if(freq[x]>0){
                freq[x]--;
                ans.push_back(x+'a');
            }
            else{
                for(int p=x+1; p<26; p++){
                    if(freq[p]>0){
                        freq[p]--;
                        ans.push_back(p+'a');
                        check=true;
                        break;
                    }
                }
                if(check){
                    string temp="";
                    for(int i=0; i<26; i++){
                        if(freq[i]>0){
                            while(freq[i]>0){
                                temp.push_back(i+'a');
                                freq[i]--;
                            }
                        }
                    }
                    sort(temp.begin(), temp.end());
                    ans+= temp;
                    return ans;
                }
                else break;
            }
        }
        check= false;
        for(int i= ans.size()-1; i>=0; i--){
            freq[ans[i]-'a']++;
            int x= ans[i]-'a';
            ans.pop_back();
            for(int p=x+1; p<26; p++){
                if(freq[p]>0){
                    freq[p]--;
                    ans.push_back(p+'a');
                    check=true;
                    break;
                }
            }
            if(check){
                string temp="";
                for(int i=0; i<26; i++){
                    if(freq[i]>0){
                        while(freq[i]>0){
                            temp.push_back(i+'a');
                            freq[i]--;
                        }
                    }
                }
                sort(temp.begin(), temp.end());
                ans+= temp;
                return ans;
            }
        }
        return "";
    }
};