// https://leetcode.com/problems/word-search

class Solution {
public:
	void solveExist(int n, int m, int index, vector<vector<int>> &visited, vector<vector<char> > &board, string word, bool &result, string &tmp) {
		// Base condition
		if (index == word.size()) {
			result = true;
			return;
		}
	
		// If character matches, then proceed; else return
		if (n >= 0 && n < board.size() && m >= 0 && m < board[0].size() && board[n][m] == word[index] && visited[n][m] == 0) {
			visited[n][m] = 1;
			tmp.push_back(board[n][m]);
			
			// Four ways to travel: D, L, R, U
			solveExist(n + 1, m, index + 1, visited, board, word, result, tmp); // Down
			solveExist(n, m - 1, index + 1, visited, board, word, result, tmp); // Left
			solveExist(n, m + 1, index + 1, visited, board, word, result, tmp); // Right
			solveExist(n - 1, m, index + 1, visited, board, word, result, tmp); // Up
			
			tmp.pop_back(); // Backtrack
			visited[n][m] = 0; // Unmark the cell
		}
	}

    bool exist(vector<vector<char>>& board, string word) {
        
        bool result = false;
        string tmp;
        vector<vector<int>> visited(board.size() , vector<int>(board[0].size(),0));

        //Check for the first matching character from the WORD
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    solveExist(i, j, 0, visited, board, word, result, tmp);
                }
            }
        }
        return result;
    }
};