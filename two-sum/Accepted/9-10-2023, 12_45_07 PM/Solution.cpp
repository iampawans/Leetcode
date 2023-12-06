// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0; i< nums.size()-1;i++){
            int diff = target - nums[i];
            auto it = std::find(nums.begin()+(i+1), nums.end(), diff);
            if(it != nums.end()){
                res.push_back(i);
                res.push_back(it - nums.begin());
                return res;
            }
        }
        return res;
    }
};