class Solution {
public:
    int dp[12+1][10000+1];
    int solve(vector<int>&coins, int amount, int index)
    {
        if(index>=coins.size() || amount==0)
            return (amount==0)?0: INT_MAX-1;

        if(dp[index][amount]!=-1)return dp[index][amount];

        int res=-1;
        if(coins[index]<=amount)
        {
            int take= 1+solve(coins, amount-coins[index], index);
            int leave= solve(coins,amount, index+1);
            dp[index][amount]=res= min(take,leave);
        }
        else{
            int leave= solve(coins, amount, index+1);
            dp[index][amount]=res=leave;
        }
        return dp[index][amount]= res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans= solve(coins, amount, 0);
        return (ans==INT_MAX-1)?-1:ans;
    }
};