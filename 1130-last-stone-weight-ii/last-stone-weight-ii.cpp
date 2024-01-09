class Solution {
public:
int tofind, ts,dp[31][3010];
    int solve(vector<int>&nums, int tsum, int index)
    {
        if(tsum>=tofind || index>=nums.size())return abs(tsum-(ts-tsum));
        if(dp[index][tsum]!=-1)return dp[index][tsum];
        int take= solve(nums, tsum+nums[index], index+1);
        int leave= solve(nums, tsum, index+1);
        return dp[index][tsum]=min(take,leave);
    }
    int lastStoneWeightII(vector<int>& stones) {
        ts=0;
        int n=stones.size();
        
        memset(dp,-1,sizeof(dp));
        if(stones.size()==0)return 0;
        if(stones.size()==1)return stones[0];
        for(int i=0;i<stones.size(); i++)
        {
            ts+=stones[i];
        }
        tofind= ts/2;
        return solve(stones, 0, 0);
    }
};