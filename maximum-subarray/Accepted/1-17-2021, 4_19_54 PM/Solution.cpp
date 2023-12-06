// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MAX =INT_MIN;
        int sum = 0;
        //kadenes algorithem
        for(int i=0; i< nums.size();i++)
        {
            sum = sum + nums[i];
            MAX = max(sum,MAX);
            if(sum < 0)
                sum = 0;
        }
        return MAX;
    }
};