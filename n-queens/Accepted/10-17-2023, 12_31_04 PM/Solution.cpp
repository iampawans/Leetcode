// https://leetcode.com/problems/n-queens

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        int x = row;
        int y = col;

        //check row
        while(y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }

        //check down diagonal
        x = row;
        y = col;
        while(x<n && y >=0){
           if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x++;
        }

        //check up diagonal
        x = row;
        y = col;
        while(x>=0 && y >=0){
           if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x--;
        }
        return true;
    }
    void solve(int col, int n, vector<vector<char>> &board, vector<vector<string>> &result, vector<vector<int>> &visited){
        //Base condition
        if(col == n){
            vector<string> tmp1;
            for(int i=0; i<n; i++){
                string tmp;
                for(int j=0; j<n; j++){
                    tmp.push_back(board[i][j]);
                }
                tmp1.push_back(tmp);
            }
            
            result.push_back(tmp1);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                //Place Queen if safe
                board[row][col] = 'Q';
                solve(col +1, n, board, result, visited);
                board[row][col] = '.'; // Backtracking
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> result;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        //vector<string> tmp;

        solve(0, n, board, result, visited);

        return result;
    }
};