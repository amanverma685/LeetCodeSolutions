class Solution {
public:
    int solve(const string &s,vector<vector<int>> &dp, int i, int j){
    
    if(i==j || i>j) return 1;   
    if(dp[i][j]!=-1)return dp[i][j];
    
    if(s[i]==s[j]) dp[i][j]=solve(s,dp,i+1,j-1);
    else dp[i][j]=0;
    
    solve(s,dp,i+1,j);
    solve(s,dp,i,j-1);
  
    return dp[i][j];  
}

string longestPalindrome(string s) {
    
    int n=s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    solve(s,dp,0,n-1);
    int x=0,y=0;
    
    for(int i=0; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(dp[i][j]==1 && j-i>y-x) x=i,y=j;
    
    return s.substr(x,y-x+1);
}
};