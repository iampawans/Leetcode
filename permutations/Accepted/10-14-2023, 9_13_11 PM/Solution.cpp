// https://leetcode.com/problems/permutations

class Solution {
public:
    void solvePermute(vector<int>& nums, vector<vector<int>> &result, vector<int> &tmp, vector<int> &taken){
        if(tmp.size() == nums.size()){
            result.push_back(tmp);
            return;
        }

        for(int i=0; i< nums.size(); i++){
            if(taken[i] == 0){
                tmp.push_back(nums[i]);
                taken[i] = 1;
                solvePermute(nums, result, tmp, taken);
                taken[i] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        vector<int> taken;
        for(int i=0; i<nums.size(); i++){
            taken.push_back(0);
        }
        solvePermute(nums, result, tmp, taken);

        return result;
    }
};