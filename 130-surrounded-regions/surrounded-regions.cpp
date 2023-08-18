class Solution {
public:
    void dfs(vector<vector<char>>& board,int row,int col,vector<vector<int>>& vis)
    {
        if(board[row][col]!='O')
        return;

        int n = board.size();
        int m = board[0].size();
        // board[row][col]='A';

        vis[row][col]=1;

        int dr[4]= {0,1,0,-1};
        int dc[4]= {-1,0,1,0};

        for(int i=0;i<4;i++)
        {
            int nrow = row + dr[i];
            int ncol = col +dc[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0)
            {   
                                // board[nrow][ncol]='a';
                dfs(board,nrow,ncol,vis);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
         int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(board[i][j]=='O'){
                        dfs(board,i,j,vis);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
                else{
                    board[i][j]='O';
                }
            }
        }

    }
};