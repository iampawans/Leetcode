// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], max = 0;
        int res=0;
        bool track = false;
        for(int i=0; i< prices.size(); i++){
            if(min > prices[i]){
                min = prices[i];
                max = 0;
            }
            
            if(max<prices[i]){
                max = prices[i];
            }
            res=std::max(res, max-min);
        }
        return res;
    }
};