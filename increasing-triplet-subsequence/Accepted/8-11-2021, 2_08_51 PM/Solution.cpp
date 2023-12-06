// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int size= nums.size();
        
        
        //[8,2,6,3,9]
        //[8,9,10,0,1]
        
        
//         for(int i=0; i< size-2;i++)
//         {
//             std::cout << nums[i] << nums[i+1] << nums[i+2]<< std::endl;
            
//             if((nums[i] < nums[i+1]) and (nums[i+1] < nums[i+2]))
//                 return true;
//         }
        
        int low = INT_MAX;
        int mid = INT_MAX;
        
        for(int i=0; i<size; i++)
        {
            if(nums[i] > mid)
                return true;
            else if(nums[i] < low)
                low = nums[i];
            else if((nums[i] < mid) and (nums[i] > low) )
                mid = nums[i];
        }
        return false;
    }
};