// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    void solveGenerateParenthesis(int open, int close, int n, vector<string> &result, string &tmp){
        //Base condition
        if(tmp.length() == n*2){
            result.push_back(tmp);
            return;
        }
        
        //Push '(' for n times
        if(open < n) {
            tmp.push_back('(');
            solveGenerateParenthesis(open+1, close, n, result, tmp);
            tmp.pop_back();
        }

        ////close '(' with ')'
        if(close <open) {
            tmp.push_back(')');
            solveGenerateParenthesis(open, close+1, n, result, tmp);
            tmp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string tmp;
        
        //0, 0 is the open and close parenthesis number
        solveGenerateParenthesis(0, 0, n, result, tmp);

        return result;
    }
};