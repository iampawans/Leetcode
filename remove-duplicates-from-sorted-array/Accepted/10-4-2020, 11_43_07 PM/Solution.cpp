// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> numb;
        vector<int> vect;
        set <int> :: iterator itr;
        
        for (int i= 0; i < nums.size(); i++)
        {
            numb.insert(nums[i]);
        }

        for (itr = numb.begin(); itr != numb.end(); ++itr) 
        { 
            vect.push_back(*itr);
        } 
        nums = vect;
        return numb.size();
    }
};