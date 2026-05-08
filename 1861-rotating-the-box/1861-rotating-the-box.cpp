class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> ans(boxGrid[0].size(),vector<char>(boxGrid.size()));
        for(int i=0; i<boxGrid.size(); i++){
            for(int j=boxGrid[0].size()-2; j>=0 ; j--){
                if(boxGrid[i][j]=='*'||boxGrid[i][j]=='.') continue;
                boxGrid[i][j]='.';
                int k=j+1;
                while(k<boxGrid[0].size()){
                    if(boxGrid[i][k]=='*'||boxGrid[i][k]=='#') break;
                    k++;
                }
                boxGrid[i][k-1]='#';
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