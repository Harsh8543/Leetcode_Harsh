class Solution {
public:
bool isSafe(vector<vector<char>> &b, int i, int j, char ch){
        for(int idx = 0; idx < 9; idx++){
            if(b[idx][j] == ch)return false;
            if(b[i][idx] == ch)return false;
            int r = 3*(i/3) + (idx/3);
            int c = 3*(j/3) + (idx%3);
            if(b[r][c] == ch)return false;

        }
        return true;
    }
    bool helper(vector<vector<char>>& board){
        for(int i = 0; i  < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] =='.'){
                    for(char k = '1'; k <= '9'; k++){
                        if(isSafe(board, i, j, k)){
                            board[i][j] = k;
                            if(helper(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};