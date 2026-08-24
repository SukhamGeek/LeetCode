class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string,int> mpp;
        int n= accounts.size();
        vector<int> par(n);
        for(int i=0; i<n; i++){
            par[i]=i;
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mpp.find(accounts[i][j])!= mpp.end()){
                    par[fp(i, par)]= fp(mpp[accounts[i][j]], par);
                }
                else mpp[accounts[i][j]]= i;
            }
        }
        vector<pair<int,int>> merge;
        for(int i=0; i<n; i++){
            merge.push_back({fp(par[i], par), i});
        }
        sort(merge.begin(), merge.end());
        unordered_set<string> st;
        int flag= merge[0].first;
        for(int i=0; i<n; i++){
            if(flag!= merge[i].first){
                vector<string> temp;
                temp.push_back(accounts[flag][0]);
                for(auto it: st){
                    temp.push_back(it);
                }
                sort(temp.begin()+1,temp.end());
                res.push_back(temp);
                st.clear();
                flag= merge[i].first;
                i--;
            }
            else{
                for(int j=1; j<accounts[merge[i].second].size(); j++){
                    st.insert(accounts[merge[i].second][j]);
                }
            }
        }
        vector<string> temp;
        temp.push_back(accounts[flag][0]);
        for(auto it: st){
            temp.push_back(it);
        }
        sort(temp.begin()+1,temp.end());
        res.push_back(temp);
        return res;
    }
    int fp(int k, vector<int>& par){
        if(par[k]==k) return k;
        return par[k]= fp(par[k], par);
    }
};