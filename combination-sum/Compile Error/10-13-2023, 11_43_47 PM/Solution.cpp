// https://leetcode.com/problems/combination-sum

class Solution {
public:
    //candidates = [2,3,5], target = 8
    // [[2,2,2,2],[2,3,3],[3,5]]]
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combo;
        //set<int> s(candidates.begin(), candidates.end());

        for(int i=0; i< candidates.size(); i++){
            
                vector<int> tmp;
            //[2,2,2,2]
            if(target % candidates[i] == 0){
                for(int j = 0 < target/candidates[i]; j++){
                    tmp.push_back[candidates[i]];
                }
            }
            else{
                //[2,3,3]
                int rem = target % candidates[i];
                if(std::find(candidates.begin(), candidates.end(), rem) != candidates.end()){
                    if(candidate[i] < rem){

                    }
                }
            }

        }
    }
};