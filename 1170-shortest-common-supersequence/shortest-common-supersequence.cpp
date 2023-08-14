class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int s = str1.size();
        int t = str2.size();
        vector<vector<int>>dp(s+1,vector<int>(t+1,0));
        for(int i=1;i<=s;i++)
        {
            for(int j=1;j<=t;j++)
            {
                if(str1[i-1]==str2[j-1])
                dp[i][j]= 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans ="";
        int i=s,j=t;
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans += str1[i-1];
                i--;
            }
            else 
            {
                ans += str2[j-1];
                j--;
            }
        }
        while(i>=1)
        {ans += str1[i-1];
        i--;}
        while(j>=1)
        {ans += str2[j-1];j--;}

    reverse(ans.begin(),ans.end());
    return ans;
    }
};