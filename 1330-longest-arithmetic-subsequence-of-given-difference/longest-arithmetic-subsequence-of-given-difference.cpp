class Solution {
public:
    int n;
 /*
 RECURSIVE APPROACH
    int  solve( vector<int>& arr,int diff ,int i, int p)
    {
        if(i>=n)return 0;
       int take=0;
       int skip=0;
       
        if(p==-10000 )
        {
            skip=solve(arr,diff,i+1,p);
            take= 1+solve(arr,diff,i+1,arr[i]);
        }
        else{
            skip=solve(arr, diff, i+1,p);
            if(arr[i]-p==diff){
            take=1+solve(arr,diff,i+1,arr[i] );
            }
        }  
        return max(skip,take);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        n= arr.size();
       
        if(n==1)return 1;
        return solve(arr, difference,0,-10000);
    }*/

    //TABULATION
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp; // Stores the maximum length at each index
        
        int ans = 1; // Initialize with the minimum length of 1
        
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (dp.find(num - difference) != dp.end()) {
                dp[num] = dp[num - difference] + 1;
            } else {
                dp[num] = 1;
            }
            
            ans = max(ans, dp[num]);
        }
        
        return ans;
    }
};