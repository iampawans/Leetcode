// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    void solveLetterCombinations(int index,int i, vector<string> &combination, vector<string> &result, string &tmp){
        //Base condition
        if(tmp.size() == combination.size()){
            result.push_back(tmp);
            return;
        }
        
        i = 0; // initialize i to 0 for every index
        while(index < combination.size() && i < combination[index].size()){

            tmp.push_back(combination[index][i]);
            solveLetterCombinations(index+1, i, combination, result, tmp);
            ++i;
            tmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string tmp;

        map<char,string> phone;
        phone.insert({'2',"abc"});
        phone.insert({'3',"def"});
        phone.insert({'4',"ghi"});
        phone.insert({'5',"jkl"});
        phone.insert({'6',"mno"});
        phone.insert({'7',"pqrs"});
        phone.insert({'8',"tuv"});
        phone.insert({'9',"wxyz"});

        vector<string> combination;
        for(char digit : digits){
            auto it = phone.find(digit);
            if(it != phone.end()){
                combination.push_back(it->second);
            }
        }

        if(digits.size() == 0){
            return result;
        }

        solveLetterCombinations(0, 0, combination, result, tmp);

        return result;
    }
};