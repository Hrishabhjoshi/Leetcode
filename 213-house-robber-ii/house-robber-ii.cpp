class Solution {
public:
    int dp[101];
    int helper(vector<int>&nums, int ind, int n)
    {
        if(ind>n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int take= nums[ind]+helper(nums, ind+2,n);
        int skip= helper(nums, ind+1,n);
        return dp[ind]=max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        memset(dp,-1,sizeof(dp));
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);

        int take_0_house= helper(nums, 0, n-2);
         memset(dp,-1,sizeof(dp));
        int take_1_house= helper(nums, 1, n-1);
        return max(take_0_house,take_1_house);
    }
};