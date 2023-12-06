// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(2);
        unordered_map<int,int> numsMap;
        for(int i = 0; i < nums.size(); i++)
        {
            if (numsMap.find(target-nums[i]) != numsMap.end())
            {
                indices[0] = numsMap[target-nums[i]];
                indices[1] = i;
                return indices; 
            }
            else
            {
                numsMap[nums[i]]=i;
            }
        }
        return {};       
    }
};