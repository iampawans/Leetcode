// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start<=end){

            //to skip the special character
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            //to skip the special character
            if(!isalnum(s[end])){
                end--;
                continue;
            }

            //If alphabate, check for palindrom
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};