// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> unMap;
        unMap.insert({')','('});
        unMap.insert({'}','{'});
        unMap.insert({']','['});
        
        for(int i = 0; i < s.length(); i++)
        {
            if((s[i] == '(') or (s[i] == '{') or (s[i] == '['))
            {
                stk.push(s[i]);
                continue;
            }
            
            if((not stk.empty()) and (unMap[s[i]] == stk.top()))
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
        
        if(stk.empty())
        {
            return true;
        }
        return false;
    }
};