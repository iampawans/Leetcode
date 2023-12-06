// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() -1;

        int mid = start + (end-start)/2;

        while(start <= end){
            if((arr[mid -1] < arr[mid]) && (arr[mid +1] < arr[mid])){
                return mid;
            }

            if(arr[mid +1] > arr[mid]){
                start = mid;
            }
            else{
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }
};