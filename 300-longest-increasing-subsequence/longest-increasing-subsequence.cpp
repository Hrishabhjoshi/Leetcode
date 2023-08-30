class Solution {
public:
int n;
/*RECURSION + MEMOISATION

int dp[2501][2501];
    int solve(vector<int>&nums, int i, int p)
    {
        if(i>=n)return 0;
        int take=0;
        if(p!=-1 && dp[i][p]!=-1)return dp[i][p];
        if(p==-1 || nums[i]>nums[p]){
            take= 1+solve(nums,i+1,i);
        }
        int leave= solve(nums, i+1, p);
        if(p!=-1)dp[i][p]=max(take,leave);
        return max(take,leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        n= nums.size();
        memset(dp,-1,sizeof(dp));
        if(n==1)return 1;
        int res= solve(nums,0, -1);
        return res;
        */
//BOTTOM UP->code story withmik
    int lengthOfLIS(vector<int>& nums)
    {
        n= nums.size();
        int maxlis=1;
        vector<int>dp(n,1);
        //dp becomes= [1,1,1,1,1,1]
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxlis=max(maxlis,dp[i]);
                }
            }
        }
        return maxlis;
    }
}; 