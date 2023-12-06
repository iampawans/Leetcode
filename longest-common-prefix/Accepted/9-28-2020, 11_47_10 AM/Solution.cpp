// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res= "";
        if(strs.size() > 0)
        {
            string str = strs[0];
            for(int i = 0; i < str.length(); i++)
            {
                int count =0;
                for(auto input : strs)
                {
                    if(i >= input.length())
                    {
                        break;
                    }
                    if(str.at(i) == input.at(i))
                    {
                        count++ ;
                    }
                }
                if(count == strs.size())
                {
                    res = res + str.at(i);
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
};