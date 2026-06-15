class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       bool b=false;
       helper(board, 0, 0, b);
       return;
    }
    void helper(vector<vector<char>>& board, int i, int j, bool& b){
        if(j>8){
            helper(board,i+1,0, b);
            return;
        }
        if(i>8){
            b=true;
            return;
        } 
        if(board[i][j]!='.'){
            helper(board,i,j+1, b);
            return;
        }
        int rs= (i/3)*3;
        int cs= (j/3)*3;
        for(int m=1; m<=9; m++){
            int check=0;
            for(int n=0; n<9; n++){
                if(board[i][n]==m+'0'){
                    check++;
                    break;
                }
                if(board[n][j]==m+'0'){
                    check++;
                    break;
                }
            }
            if(check>0) continue;
            for(int n=rs; n<rs+3; n++){
                for(int p=cs; p<cs+3; p++){
                    if(board[n][p]==m+'0'){
                        check++;
                        break;
                    }
                }
            }
            if(check>0)continue;
            board[i][j]=m+'0';
            helper(board,i,j+1,b);
            if(b) return;
            board[i][j]='.';
        }        
    }
};