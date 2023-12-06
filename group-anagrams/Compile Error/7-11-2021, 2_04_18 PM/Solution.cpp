// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int size = strs.size();
        vector<vector<string>> anagram;
        
        if(size >1)
        {
        
        for(int i = size-1; i >= 0 ; i--)
        {
            set<string> aset;
            vector<string> vec;
            for(int j =size-1; j >=0 ; j--)
            {
                string s1 = strs[i];
                string s2 = strs[j];
                if(s1 == "" and s2 == "")
                {
                    vec.push_back(strs[i]);
                    vec.push_back(strs[j]);
                    return (anagram.push_back(vec));
                }
                
                sort(s1.begin(), s1.end());
                sort(s2.begin(), s2.end());
                
                if(s1 == s2)
                {
                    aset.insert(strs[i]);
                    aset.insert(strs[j]);
                }
                else
                {
                    aset.insert(strs[i]);
                }
            }
            vec(aset.begin(),aset.end());
            if(find(anagram.begin(),anagram.end(),vec) == anagram.end())
                anagram.push_back(vec);
        }
        }
        else
        {
            anagram.push_back(strs);
        }
        return anagram;
        
    }
};