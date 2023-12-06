// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0)
        {
            int pos = x % 10;
            x = x / 10;
            if(res > INT_MAX/10 || res < INT_MIN/10)
            {
                return 0;
            }
            res = res * 10 + pos;
        }
        return res;    
    }
};