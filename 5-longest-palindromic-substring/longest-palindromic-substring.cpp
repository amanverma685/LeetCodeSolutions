class Solution {
public:
    int solve(string &str,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j or i>j)
        return 1;
        if(dp[i][j]!= -1)
        return dp[i][j];

        if(str[i]==str[j])
        dp[i][j]=solve(str,i+1,j-1,dp);

        else dp[i][j]=0;
        solve(str,i+1,j,dp);
        solve(str,i,j-1,dp);
        return dp[i][j];
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        solve(s,0,n-1,dp);
        int x=0,y=0;

        for(int i=0;i<=n;i++)
        {
            for(int j= i+1;j<=n;j++)
            {
                if(dp[i][j]==1 and j-i >y-x)
                x=i,y=j;
            }
        }
        return s.substr(x,y-x+1);
    }
};