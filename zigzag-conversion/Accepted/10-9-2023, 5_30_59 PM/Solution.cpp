// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        string result = "";
        for(int i=0; i <s.size();){
            //Insert first coulumn in all rows ex: PAY
            for(int j=0; j<numRows; j++){
                if(i <s.size()){
                    v[j].push_back(s[i]);
                    i++;
                }
            }
            //Insert to second column exluding first and last row- ex : P
            for(int k =numRows-2; k>0 ; k--){
                if(i <s.size()){
                    v[k].push_back(s[i]);
                    i++;
                }              
            }
        }

        for(int i=0; i< v.size(); i++){
            string str(v[i].begin(), v[i].end());
            result.append(str);
        }

        return result;
    }
};