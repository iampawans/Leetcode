// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        int convetedValue = 0;
        unordered_map<char, int> roman ={{'I', 1}, {'V', 5}, {'X', 10},  {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        
        for(int i = 0; i<s.length(); i++) 
        {
            //cout << s.at(i) << endl;
            if(roman.find(s.at(i)) != roman.end())
            {
                //cout << roman.at(s.at(i)) << endl;
                if(((i+1) < s.length()) and (roman.at(s.at(i)) < roman.at(s.at(i+1))))
                {
                    convetedValue = convetedValue - roman.at(s.at(i));
                }
                else
                {
                    convetedValue =  convetedValue + roman.at(s.at(i));
                }
            }
        }
        return convetedValue;
    }
};