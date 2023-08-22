class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>& matrix,int index1,int index2,int n, int m)
    {
        if(index2<0 or index2>m )
        return 1e9;

        if(index1 == n)
        return matrix[index1][index2];

        if(dp[index1][index2]!= -1)
        return dp[index1][index2];

        int ld = solve(dp,matrix,index1+1,index2-1,n,m);
        int d = solve(dp,matrix,index1+1,index2,n,m);
        int rd = solve(dp,matrix,index1+1,index2+1,n,m);

        return dp[index1][index2]= matrix[index1][index2]+ min(ld,min(d,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans =INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     ans = min(solve(dp,matrix,0,i,n-1,m-1),ans);
        // }
        // return ans;
        dp[0] = matrix[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int l = 1e9,r=1e9,d=1e9;
                if(j>0)
                l = dp[i-1][j-1];
                if(j<n-1)
                r = dp[i-1][j+1];
                d = dp[i-1][j];

                dp[i][j] = matrix[i][j] + min(l,min(r,d));

            }
        }
        for(int i=0;i<n;i++)
        {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};