// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //["eat","tea","tan","ate","nat","bat"]
        // Use map where key is sorted string and value is string of the input vector
        // ex : key = aet and value = "eat","tea","ate"
        
        std::map<std::string, std::vector<std::string>> mp;
        
        vector<vector<string>> anagram;
        
        for(auto val : strs)
        {
            std::string tmp;
            tmp = val;
            sort(val.begin(), val.end());
            mp[val].push_back(tmp);
        }
        
        for(auto m : mp)
        {
            anagram.push_back(m.second);
        }
        
        return anagram;
    }
};