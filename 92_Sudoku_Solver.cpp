class Solution {
public:

    bool isValid(vector<vector<char>> & board, int row, int col, char val){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == val){
                return false;
            }
            if(board[i][col] == val){
                return false;
            }
        }

        int r = row/3;
        r = r*3;
        int c = col/3;
        c = c*3;

        for(int i = r; i <= r+2; i++){
            for(int j = c; j <= c+2; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }

        return true;
    }

    bool soln(vector<vector<char>>& board){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            bool res = soln(board);
                            if(res == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        soln(board);
    }
};