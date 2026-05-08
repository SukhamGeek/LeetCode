class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> ans(boxGrid[0].size(),vector<char>(boxGrid.size()));
        for(int i=0; i<boxGrid.size(); i++){
            int lp= boxGrid[0].size()-1;
            for(int j=boxGrid[0].size()-1; j>=0 ; j--){
                if(boxGrid[i][j]=='*'){
                    lp=j-1;
                    continue;
                }
                else if(boxGrid[i][j]=='.') continue;
                boxGrid[i][j]='.';
                boxGrid[i][lp]='#';
                lp--;
                int k=j+1;
            }
        }
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[0].size(); j++){
                ans[i][j]= boxGrid[j][i];
            }
        }
        for(int i=0; i<ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};