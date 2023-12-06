// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        std::vector<int> res;
        int count =1;int i=0;
        while(i < arr.size()+k){
            if((i<arr.size()) && (count == arr[i])){
                i++;
            }
            else{
                res.push_back(count);
            }

            if(res.size()==k){
                 return res[k-1];
            }
            count++;
        }
        
        return 0;
    }
};