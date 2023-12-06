// https://leetcode.com/problems/combination-sum

class Solution {
public:
    bool isSafe(int index, vector<int>& candidates, int target){
        if(index < candidates.size() && target-candidates[index] >=0){
            return true;
        }
        return false;
    }

    void solveCombinationSum(int index, vector<int>& candidates, int target, vector<int> &combination, vector<vector<int>> &result){

        // Base condition
        if(target == 0){
            result.push_back(combination);
            return;
        }

        while(isSafe(index, candidates, target)){
            combination.push_back(candidates[index]);
            solveCombinationSum(index, candidates, target-candidates[index], combination, result);
            ++index;
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;

        solveCombinationSum(0, candidates, target, combination, result);
        return result;
    }
};