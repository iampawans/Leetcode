// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {

        stringstream str(s);
        string res;
        while(str>>res){}
        return res.length();
    }
};