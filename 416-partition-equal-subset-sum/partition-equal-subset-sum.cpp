class Solution {
public:
  bool Partition(vector<int>& nums , int sum ,int n , vector<vector<int>>&dp ) {
        if(n==0 && sum!=0){
            return false;
        }
        if(sum<0){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(nums[n-1]<=sum){
            dp[n][sum] = Partition(nums,sum-nums[n-1],n-1,dp)|| Partition(nums,sum,n-1,dp);
        }
        else{
            dp[n][sum] = Partition(nums,sum-nums[n-1],n-1,dp)|| Partition(nums,sum,n-1,dp);
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        bool res=false;
        int n= nums.size();
        if(n==0)return false;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        else{
            int m= sum/2;
            vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return Partition(nums,m,n,dp);
        }
        return res;
    }
};