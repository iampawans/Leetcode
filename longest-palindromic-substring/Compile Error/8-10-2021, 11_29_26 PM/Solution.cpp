// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        
        //babad 
        //insert to set. if found in set, update char str and pos.
        // last elementt and pos is found.
        
        
        std::unordered_set<char> st;
        int size = s.length();
        int pos; char str;
        std::string palindrom;
        
        if(s.empty())
            return "";
        
        if((size <=2) and (s[0] != s[1])
        {
            std::string tmp;
            tmp=s[0];
            return tmp;
        }
        
        for(int i=0; i< size;i++)
        {
            if(st.find(s[i]) == st.end())
            {
                st.insert(s[i]);
            }
            else
            {
                str = s[i];
                pos = i;
            }
            
        }
        
        
        size_t found = s.find(str);
        if(found != std::string::npos)
        {
            palindrom = s.substr(found,pos);
        }
            
        return palindrom;
        
    }
};