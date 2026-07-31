class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n= beginWord.size();
        int res= 0;
        if(find(wordList.begin(), wordList.end(), endWord)== wordList.end()) return 0;
        vector<vector<int>> adj(wordList.size());
        for(int i=0; i<wordList.size(); i++){
            for(int j=i+1; j<wordList.size(); j++){
                int count=0;
                for(int k=0; k<n; k++){
                    if((wordList[i][k]- wordList[j][k])!=0){
                        count++;
                    }
                    if(count>1) break;
                }
                if(count==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        bool flag= false;
        for(int i=0; i<wordList.size(); i++){
            if(wordList[i]== beginWord){
                q.push(i);
                flag= true;
                break;
            }
        }
        vector<int> vis(wordList.size(), -1);
        if(!flag){
            for(int i=0; i<wordList.size(); i++){
                int count=0;
                for(int k=0; k<n; k++){
                    if((wordList[i][k]- beginWord[k])!=0){
                        count++;
                    }
                    if(count>1) break;
                }
            if(count==1){
                q.push(i);
                vis[i]=1;
            }
            }
        }
        while(!q.empty()){
            int s= q.size();
            for(int j=0; j<s; j++){
                int k= q.front();
                q.pop();
                if(wordList[k]== endWord){
                    if(flag) return res+1;
                    return res+2;
                    break;
                }
                for(auto it: adj[k]){
                    if(vis[it]== -1){
                        q.push(it);
                        vis[it]=1;
                    } 
                }               
            }
            res++;
        }
        return 0;       
    }
};