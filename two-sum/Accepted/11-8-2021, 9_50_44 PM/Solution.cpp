// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        for(int i=0; i<nums.size();i++)
        {
            int val=target-nums[i];
            
            std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), val);
            if(it != nums.end())
            {
                int id=std::distance(nums.begin(), it);
                if(id != i)
                {
                    res.push_back(i);
                    res.push_back(id);
                    return res;
                }
            }
        }
        return res;
    }
};