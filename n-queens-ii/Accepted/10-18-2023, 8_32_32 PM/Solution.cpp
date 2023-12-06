// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    bool isSafe(int row, int col, int n, vector<vector<int>> &board){
        int x = row;
        int y = col;

        //Check for the left row. In right there is no entry so no need to check
        while(y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }

        x = row;
        y = col;

        //Upward diagonal in left. In right there is no entry so no need to check
        while(x >= 0 && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;

        //Downward diagonal in left. In right there is no entry so no need to check
        while(x < n && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            x++;
            y--;
        }

        return true;
    }
    void solveTotalNQueens(int col, int n, vector<vector<int>> &board, int &result, vector<int> &tmp){
        if(col == n){
            result = result+1;
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row, col, n, board)){
                //All safe, update board with 1
                board[row][col] = 1;
                solveTotalNQueens(col +1, n, board, result, tmp);
                board[row][col] = 0; //Backtracking
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        int result =0;
        vector<int> tmp;

        solveTotalNQueens(0, n, board, result, tmp);

        return result;
    }
};