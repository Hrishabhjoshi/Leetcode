class Solution {
public:

//RECURSION +MEMOIZATION
/*
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
    }*/

//BOTTOM UP
    int rob(vector<int>& nums)
    {
        //bottom up of house robber 1 when starting from 9 house and statring from 1 house 
        //then find max from both the bottom ups
        
        //state define-> t[i]=profit when we have i houses;
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>t(n+1,0);
         t[0]=0;

        for(int i=1 ; i<=n-1; i++)
        {
            int skip= t[i-1];
            int take= nums[i-1]+ ((i-2>0)?t[i-2]:0);
            t[i]=max(skip,take);
        }
        int res1= t[n-1];
        //case 2
        t.clear();
        t[0]=0;
        t[1]=0;
        for(int i=2; i<=n; i++)
        {
            int skip= t[i-1];
            int take= nums[i-1]+ ((i-2>0)?t[i-2]:0);
            t[i]=max(skip,take);
        }
        int res2= t[n];
        return max(res1,res2);
    }
};