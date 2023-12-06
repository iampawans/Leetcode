// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //int i=0;
        vector<int> res;
        
        //If vector empty
        if(nums.empty())
            return 0;
        
        //If vect has only one entry
        if(nums.size() == 1)
            return 1;
        
        res.push_back(nums[0]);
        
        for(int i=1; i < nums.size(); i++)
        {
            
            if(nums[i] > nums[i-1])
            {
                 res.push_back(nums[i]);             
            }
        }
        
        nums = res;
        
        return nums.size();
    }
};