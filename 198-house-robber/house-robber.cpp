class Solution {
public:
    // int helper(vector<int>&dp,int idx, vector<int>&nums)
    // {
    //     if(idx>=nums.size())return 0;
    //     if(dp[idx]!=-1)return dp[idx];
    //     //if i skip the house;
    //     int skip= helper(dp,idx+1,nums);
    //     //if i looot the house
    //     int loot= helper(dp,idx+2,nums)+nums[idx];
    //     return dp[idx]= max(skip,loot);
    // }
    // int rob(vector<int>& nums) {
    //     vector<int>dp(nums.size()+1,-1);
    //     return helper(dp,0, nums);
    // }


//     int rec(vector<int>& nums,int idx,vector<int>&dp){
//        if(idx >= nums.size()) return 0;
//        if(dp[idx] != -1) return dp[idx];
//        return dp[idx] = max(rec(nums, idx+1, dp), nums[idx] + rec(nums, idx+2, dp));
//   }
//   int rob(vector<int>& nums) {
//       vector<int>dp(nums.size()+1,-1);
//       return rec(nums,0,dp);
//  }


//BOTTOM UP APPROACH
int rob(vector<int>& nums)
{
    //dp[i]= max stolen money till i th house  
    int n= nums.size();
    if(n==1)return nums[0];
    vector<int>dp(n+1,0);

    //if no house;
    dp[0]=0;
    dp[1]=nums[0];
    for(int i=2; i<=n; i++)
    {
        int steal= nums[i-1]+dp[i-2];
        int skip= dp[i-1];
        dp[i]=max(steal,skip);
    }
    return dp[n];
} 
};