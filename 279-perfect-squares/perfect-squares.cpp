class Solution {
public:
    int solve(int st, int n,vector<int>&dp)
    {
        if(n==0)return 0;
        if(n<0)return 1e8;
        if(st*st>n)return 1e8;
        if(dp[n]!=0)return dp[n];
        int take;
        if(st*st<=n)
        {
            take=1+solve(st, n-(st*st),dp);
        }
        int leave= solve(st+1, n,dp);
        return dp[n]=min(take,leave);
    }
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        if(n==1)return 1;
        return solve(1, n,dp);
    }
};