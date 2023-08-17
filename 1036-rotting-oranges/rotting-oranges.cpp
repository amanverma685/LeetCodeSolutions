class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        int ans =0;
        int countFresh =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j,0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1)
                countFresh++;
            }
        }
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,-1,0,1};

        while(!q.empty())
        {
            int row = q.front()[0];
            int col = q.front()[1];
            int time = q.front()[2];
            q.pop();
            ans = time;
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    countFresh--;
                    q.push({nrow,ncol,time+1});

                }
            }
        }

        if(countFresh!=0)
        return -1;
        return ans;

    }
};