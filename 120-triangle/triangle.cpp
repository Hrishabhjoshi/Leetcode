class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(triangle, 0, 0, memo);
    }

private:
    int dp(vector<vector<int>>& triangle, int idx, int row, vector<vector<int>>& memo) {
        if (row == triangle.size()) return 0;
        if (memo[row][idx] != -1) return memo[row][idx];

        int down = dp(triangle, idx, row + 1, memo);
        int downRight = dp(triangle, idx + 1, row + 1, memo);
        return memo[row][idx] = triangle[row][idx] + min(down, downRight);
    }
    //  public:
    //  int solve(vector<vector<int>>&triangle, int row, int col,vector<vector<int>>dp)
    //  {
    //      int n= triangle.size();
         
    //      if(row==triangle.size())return 0;
    //      if(dp[row][col]!=0)return dp[row][col];
    //      int take, leave;
    //      take= triangle[row][col]+solve(triangle, row+1, col,dp);
    //      leave= triangle[row][col]+solve(triangle, row+1, col+1,dp);
    //      return dp[row][col]=min(take,leave);

    //  }
    //  int minimumTotal(vector<vector<int>>& triangle)
    //  {
    //      int n= triangle.size();
    //      vector<vector<int>>dp(n, vector<int>(n,0));
    //      if(n==0)return 0;
    //      if(n==1){
    //          int mine= *min_element(triangle[0].begin(), triangle[0].end());
    //          return mine;
    //      }
    //     return solve(triangle, 0,0,dp);
    //  }
};