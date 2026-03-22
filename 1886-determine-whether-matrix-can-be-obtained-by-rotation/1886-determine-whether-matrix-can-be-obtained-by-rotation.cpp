class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m= mat.size();
        int n= mat[0].size();
        int d=0;
         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]!=target[i][j]){
                    d++;
                    break;
                }
            }
            if(d>0) break;   
        }
        if(d==0) return true;
        int f=0;
        for(int c=0; c<3; c++){
            for(int i=0; i<m; i++){
                for(int j=i; j<n; j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(auto& p: mat){
                reverse(p.begin(), p.end());
            }
            int check=0;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j]!=target[i][j]){
                        check++;
                        break;
                    }
                }
                if(check>0) break;   
            }
            if(check==0){
                f++;
                break;
            }
        }
        if(f>0) return true;
        return false;
    }
};