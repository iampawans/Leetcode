// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0;
        int max=0;

        unordered_set<char> _set;
        
        for(int j=0;j<s.length(); j++)
        {
            _set.clear();
            count=0;
        for(int i=j; i<s.length(); i++)
        {   
            if(_set.find(s[i]) == _set.end())
            {
                //means not found
                _set.insert(s[i]);
                 count++;
                if(count> max)
                {
                    max=count;
                }
            }
            else
            {
                break;
            }         
        }   
        }
            return max;
    }
};