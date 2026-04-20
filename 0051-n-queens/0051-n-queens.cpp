class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            vector<int>vec={i};
            helper(ans, n, 1, i, vec);
        }
        vector<vector<string>> res(ans.size(), vector<string>(n));
        for(int i=0; i<res.size(); i++){
            for(int j=0; j<res[0].size(); j++){
                for(int k=0; k<n; k++){
                    res[i][j].push_back('.');
                }
            }
        }
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[0].size(); j++){
                res[i][j][ans[i][j]]='Q';
            }
        }
        return res;
    }
    void helper(vector<vector<int>>&ans, int n, int ind, int prev, vector<int>&row){
        if(ind==n){
            ans.push_back(row);
            return;
        }
        int check=0;
        for(int j=0; j<n; j++){
            if(find(row.begin(), row.end(), j) == row.end()){
                int temp= row.size();
                int k=0;
                int flag=0;
                while(temp>0){
                    if(abs(row[k]-j)==abs(k-ind)){
                        flag++;
                        break;
                    }
                    temp--;
                    k++;
                }
                if(flag>0) continue;
                check++;
                row.push_back(j);
                helper(ans,n, ind+1, j, row);
                row.pop_back();
            }
        }
    }
};