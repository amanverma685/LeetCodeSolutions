class Solution {
public:
    int solve(vector<vector<int>>&dp,int index1,int index2, vector<vector<int>>&triangle)
    {
        int row = triangle.size();

        if(index1==row-1)
        return triangle[index1][index2];

        if(dp[index1][index2]!=-1)
        return dp[index1][index2];

        int down = 0;
        if(index1<row-1)
        {
            down = triangle[index1][index2] + solve(dp,index1+1,index2,triangle);
        }
        int downR = 0;
        if(index2<row+1)
        {
            downR = triangle[index1][index2] + solve(dp,index1+1,index2+1,triangle);
        }

        return  dp[index1][index2]=min(down,downR);

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(dp,0,0,triangle);
    }
};