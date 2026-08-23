class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        int ans=0;
        vector<int>par(n);
        for(int i=0; i<n; i++){
            par[i]=i;
        }
        vector<int> rank(n,0);
        for(int i=0; i<n; i++){                
            for(int j=i+1; j<n; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]== stones[j][1]){
                    uni(i, j, rank, par);
                }
            }
        }
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[fp(i, par)]++;
        }
        for(auto it:mpp){
            int k= it.second;
            ans+= k-1;
        }
        return ans;
    }
    void uni(int i, int j, vector<int>& rank, vector<int>& par){
        int pi= fp(i, par);
        int pj= fp(j, par);
        if(pi== pj) return;
        if(rank[pi]< rank[pj]) par[pi]= pj;
        else if(rank[pi] > rank[pj]) par[pj]= pi;
        else{
            par[pj]= pi;
            rank[pi]++;
        }
    }
    int fp(int k, vector<int>& par){
        if(k== par[k]) return k;
        return par[k]= fp(par[k], par);
    }
};