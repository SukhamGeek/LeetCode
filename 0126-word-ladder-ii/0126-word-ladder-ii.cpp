class Solution {
unordered_map<string,int>mpp;
vector<vector<string>> res;

private:
    void dfs(string word, vector<string> seq, string& beginWord){
        if(word== beginWord){
            reverse(seq.begin(), seq.end());
            res.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps= mpp[word];
        for(int i=0; i<beginWord.size(); i++){
            char ori= word[i];
            for(char c='a'; c<='z'; c++){
                word[i]= c;
                if(mpp.find(word)!= mpp.end() && mpp[word]== steps-1){
                    seq.push_back(word);
                    dfs(word, seq, beginWord);
                    seq.pop_back();
                }
            }
            word[i]= ori;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n= wordList.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string>q;
        q.push(beginWord);
        mpp[beginWord]=1;
        st.erase(beginWord);
        int sz= beginWord.size();
        while(!q.empty()){
            string word= q.front();
            int steps= mpp[word];
            q.pop();
            if(word== endWord) break;
            for(int i=0; i<sz; i++){
                char ori= word[i];
                for(char ch= 'a'; ch<= 'z'; ch++){
                    word[i]= ch;
                    if(st.count(word)){
                        q.push(word);
                        mpp[word]= steps+1;
                        st.erase(word);
                    }
                }
                word[i]= ori;
            }
        }
        if(mpp.find(endWord)!= mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord);
        }
        return res;
    }
    
};