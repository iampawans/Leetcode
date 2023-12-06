// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int firstOccurance(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;

        int first = -1;
        int mid = start + (end-start)/2;
        while(start <= end){
            if(nums[mid] == target){
                first = mid;
                end = mid -1;
            }
            else if(nums[mid] > target){
                end = mid -1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return first;
    }

    int lastOccurance(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;

        int last = -1;
        int mid = start + (end-start)/2;
        while(start <= end){
            if(nums[mid] == target){
                last = mid;
                start = mid +1;
            }
            else if(nums[mid] > target){
                end = mid -1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(firstOccurance(nums, target));
        res.push_back(lastOccurance(nums, target));

        return res;
    }
};