// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> a;
        int res=0;
        a.push(-1);

        for(int i=0; i< s.length(); i++){
            if(s[i] == '('){
                a.push(i);
            }
            else{
                a.pop();
                if(a.empty()){
                    a.push(i);
                }
                else{
                    res = max(res, i-a.top());
                }
            }
        }
        return res;
    }
};