class Solution {
public:
    int path(vector<vector<int>>&grid,vector<vector<int>>&dp,int index1,int index2)
    {   
        if(index1<0 or index2<0)
        return 0;

        if(grid[index1][index2]==1)
        return 0;

        if(index1==0 and index2==0)
        return 1;

        if(dp[index1][index2]!=1)
        dp[index1][index2];

        int up=0; int left =0;
        if(index1-1>=0 and grid[index1-1][index2]!= 1)
        up = path(grid,dp,index1-1,index2);

        if(index2-1>=0 and grid[index1][index2-1]!= 1)
        left = path(grid,dp,index1,index2-1);
        
        return dp[index1][index2]= up +left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        // return path(grid,dp,m-1,n-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                    
                if(i==0 and j==0)
                    {
                        dp[i][j]=1;
                        continue;
                    }
                int up=0,left =0;

                if(i>0)
                up = dp[i-1][j];
                if(j>0)
                left = dp[i][j-1];

                dp[i][j] = up+left;

            }
        }
        return dp[n-1][m-1];
    }
};