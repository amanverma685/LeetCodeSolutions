class Solution {
public:
    vector<vector<int>>solve(vector<vector<int>>&mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int dr[4]= {1,0,-1,0};
        int dc[4]= {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            dis[row][col]= dist;
            for(int i=0;i<4;i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and vis[nrow][ncol]==0)
                {   
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                }

            }
        }
        return dis;

    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> ans = solve(mat);
        return ans;

    }
};