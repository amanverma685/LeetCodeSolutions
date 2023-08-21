class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>grid,int index1,int index2)
    {
        if(index1<0 or index2<0)
        return 1e9;

        if(index1==0 and index2==0)
        return grid[0][0];

        if(dp[index1][index2] != 1e9)
        return dp[index1][index2];

        int up =1e9; int left =1e9;

        up  = grid[index1][index2]+solve(dp,grid,index1-1,index2);

        left  = grid[index1][index2]+solve(dp,grid,index1,index2-1);

        return dp[index1][index2] = min(up,left);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        // return solve(dp,grid,n-1,m-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 and j==0)
                dp[i][j]= grid[i][j];
                else
                {
                    int up = 1e9,left = 1e9;
                    if(i>0)
                    up = dp[i-1][j];
                    if(j>0)
                    left = dp[i][j-1];

                    dp[i][j]= grid[i][j]+min(up,left);
                }
            }
        }
        return dp[n-1][m-1];

    }
};