// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        string str = "";
        int result=0;
                
        for(int i =0; i< s.length(); i++)
        {
            if(s[i] != ' ')
            {
                str = str + s[i];
                result = str.length();
            }
            else
            {
                str = "";
            }
        }
       
        return result;
        
    }
};