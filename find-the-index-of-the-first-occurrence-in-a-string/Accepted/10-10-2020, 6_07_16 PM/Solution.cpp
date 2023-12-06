// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
       
        //int size = needle.length();
        
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        
        std::size_t found = haystack.find(needle);
        
    return found;
    }
};