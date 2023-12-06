// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        if(s.length()==1){
            return false;
        }
        stack<char> st;
        for(int i=0; i< s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                continue;
            }
            
            if(!st.empty() && ((s[i]==')' && st.top() == '(') || (s[i]=='}' && st.top() == '{') || (s[i]==']' && st.top() == '['))){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};