// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        int size = nums.size();
        std::sort(nums.begin(),nums.end());
        
        int sum = ((nums[size-1]*nums[size-2])-(nums[0]*nums[1]));
        
        return sum;
    }
};