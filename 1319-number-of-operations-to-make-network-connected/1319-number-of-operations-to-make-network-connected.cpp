class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> par(n);
        int p= connections.size();
        if(p< (n-1)) return -1;
        for(int i=0; i<n; i++){
            par[i]= i;
        }
        vector<int> rank(n,0);
        for(int i=0; i<p; i++){
            uni(connections[i][0], connections[i][1], rank, par);
        }
        unordered_set<int> st;
        int c=0;
        for(int i=0; i<n; i++){
            if(!st.count(fp(i, par))){
                c++;
                st.insert(fp(i, par));
            }
        }
        return c-1;
    }
    void uni(int u, int v, vector<int>& rank, vector<int>& par){
        int up= fp(u, par);
        int vp= fp(v, par);
        if(up==vp) return;
        if(rank[up]<rank[vp]) par[up]=vp;
        else if(rank[up]>rank[vp]) par[vp]= up;
        else{
            par[vp]= up;
            rank[up]++;
        }
        return;
    }
    int fp(int k, vector<int>& par){
        if(par[k]==k) return k;
        return par[k]= fp(par[k], par);
    }
};