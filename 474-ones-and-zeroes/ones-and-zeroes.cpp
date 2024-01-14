class Solution {
public:
    int s;
    int dp[601][101][101];
    int solve(vector<string>&strs, int m, int n, int index)
    {
       
        if(index>=s)return 0;
        if(dp[index][m][n]!=-1)return dp[index][m][n];
        int count1= count(strs[index].begin(), strs[index].end(), '1');
        int count0= strs[index].size()-count1;
        int take,leave;
        if(m-count0>=0 && n-count1>=0){
            take= 1+solve(strs,m-count0 , n-count1, index+1);
            leave= solve(strs,m,n, index+1);
            return dp[index][m][n]=max(take, leave);
        }
        else{
        return dp[index][m][n]=solve(strs,m, n, index+1);
        }

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        s=strs.size();
        memset(dp,-1,sizeof(dp));
        if(s==0)return 0;
        return solve(strs,m,n,0);
    }
};