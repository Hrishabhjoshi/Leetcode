//Input: grid = [[1,2,3],[4,5,6]]
//Output: 12

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,1e9));
        queue<pair<int,int>>q;
        vis[0][0]=grid[0][0];
        q.push({0,0});

        while(!q.empty())
        {
            int row= q.front().first;
            int col= q.front().second;
            int nrow=row+1;
            int ncol=col+1;
            if(row==n-1 && col==m-1){
                return vis[row][col];
            }
            q.pop();
            if(nrow<n){
                if(vis[row][col]+grid[nrow][col]< vis[nrow][col]){
                    q.push({nrow,col});
                    vis[nrow][col]=vis[row][col]+grid[nrow][col];
                }
            }
            if(ncol<m){
                if(vis[row][col]+grid[row][ncol]< vis[row][ncol]){
                    q.push({row,ncol});
                    vis[row][ncol]=vis[row][col]+grid[row][ncol];
                }
            }
        }
        return 67;
    }
};