// https://leetcode.com/problems/combinations

class Solution {
public:
    void solve(vector<int> &nums, int k, vector<vector<int>> &result, vector<int> &tmp, vector<int> &taken){
        if(tmp.size() == k){
            result.push_back(tmp);
            return;
        }

        for(int i=0; i< nums.size(); i++){
            if(!taken[i] && tmp.size() < k){
                
                //This is to remove duplicates like [2,1]
                if(tmp.size()>0 && tmp[tmp.size()-1] > nums[i]){
                    continue;
                }

                tmp.push_back(nums[i]);
                taken[i] =1;
                //recurssion
                solve(nums, k, result, tmp, taken);
                //Backtracking
                taken[i] =0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;
        vector<int> taken;
        vector<int> nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
            taken.push_back(0);
        }
        solve(nums, k, result, tmp, taken);

        return result;
    }
};