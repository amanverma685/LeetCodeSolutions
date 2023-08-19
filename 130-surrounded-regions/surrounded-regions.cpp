class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col)
    {
        int n=board.size();
        int m = board[0].size();

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        vis[row][col]=1;

        for(int i=0;i<4;i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and board[nrow][ncol]=='O' and vis[nrow][ncol]==0)
            {
                dfs(board,vis,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or i==n-1 or j==0 or j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                        dfs(board,vis,i,j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                board[i][j]='O';
                else if(vis[i][j]==0)
                    board[i][j]='X';

            }
        }
        
    }
    
};