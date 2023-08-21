class Solution {
public:
    int returnPath(vector<vector<int>>&dp,int index1,int index2){
    if(index1<0 or index2<0)
        return 0;
    if(index1==0 and index2==0)
        return 1;
    if(dp[index1][index2]!=-1)
    return dp[index1][index2];

    int up  = returnPath(dp,index1-1,index2);
    int left  = returnPath(dp,index1,index2-1);
    return dp[index1][index2]= up+left;
      
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return returnPath(dp,m-1,n-1);

    }
};