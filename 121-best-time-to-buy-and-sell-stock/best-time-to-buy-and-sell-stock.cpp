class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxp=0 , j=0;
       for(int i=0; i<prices.size(); i++)
       {
            maxp=max(maxp, prices[i]-prices[j]);
            if(prices[i]<prices[j])j=i;
       } 
       return maxp;
    }
};