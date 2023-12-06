// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0){
            return 0;
        }

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std:sort(nums1.begin(), nums1.end());

        int size = nums1.size();
        float res;
        int mid=size/2;
        if(size % 2 == 0){
            float med = nums1[mid] + nums1[mid-1];
            res = med / 2;
        }
        else
        {
            res = nums1[mid];
        }
        return res;
    }
};