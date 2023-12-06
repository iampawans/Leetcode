// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        
        if (n==0){
            return 0;
        }
        if(h<n){
            return -1;
        }
        
        for (int i=0; i<=h-n; i++ ){    
            for (int j = 0; j<n; j++){   
                if(haystack[i+j]==needle[j] && j==n-1){
                    return i;
                }
                else if (haystack[i+j]!=needle[j]){
                    break;
                }                
            }      
        }     
        return -1;      
    }
};