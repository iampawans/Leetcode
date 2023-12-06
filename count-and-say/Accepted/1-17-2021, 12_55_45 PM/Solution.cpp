// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        int number, count=0;
        if(n == 1)
        {
            return "1";
        }
        if(n == 2)
        {
            return "11";
        }        
        
        string result = "11";
        
        for(int i = 3; i <= n ; i++)
        { 
            string temp = "";
            int count = 1;
            int length = result.length();
            for(int j = 1 ; j < length + 1 ; j++)
            {
                if(result[j-1] == result[j])
                {
                    count++;
                }
                else
                {
                    temp = temp + to_string(count) + result[j-1];
                    count = 1;
                }
            }
            result= temp;
        }
        return result;
    }
};