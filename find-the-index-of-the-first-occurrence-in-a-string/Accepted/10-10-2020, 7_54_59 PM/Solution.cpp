// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
               
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
                
    return haystack.find(needle);
    }
};
