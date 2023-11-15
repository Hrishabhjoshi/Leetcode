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
};