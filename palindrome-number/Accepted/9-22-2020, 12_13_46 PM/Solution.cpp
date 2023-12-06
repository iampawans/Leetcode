// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        bool aStatus = false;
        int res = 0;
        int input = x;

        while ((x != 0) and (x > 0))
        {
            int pos = x % 10;
            x /= 10;
            if (res > INT_MAX/10 || res < INT_MIN/10)
            {
                return false;
            }
            res = res * 10 + pos;
        }
        if(res == input)
        {
            aStatus = true;
        }
        
        return aStatus;
    }
};