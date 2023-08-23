class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]!=0)
        return -1;

        vector<pair<int,int>> path ={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            vis[row][col]=1;

            if(row==n-1 and col ==n-1)
            return dist;

            {
                for(int i=0;i<8;i++)
                {
                    int nrow = row + path[i].first;
                    int ncol = col + path[i].second;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[ncol][nrow]==0 and vis[nrow][ncol]!=1)
                    {   
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol},dist+1});
                    }
                }
            }
        }
        return -1;
    }
};