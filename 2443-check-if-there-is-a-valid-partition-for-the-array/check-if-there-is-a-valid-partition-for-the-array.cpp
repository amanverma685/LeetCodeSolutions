class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return false;
        vector<int>dp(3,false);
        dp[0]=true;
        dp[1] = false;
        if(n>1)
        dp[2]= (nums[0]==nums[1]);

        else dp[2]=false;

        for(int i=2;i<n;i++)
        {
            bool curr = false;
            // check for two equal elements 
            if(nums[i]==nums[i-1] and dp[1])
                curr = true;

            else if(nums[i]==nums[i-1] and nums[i-1]==nums[i-2] and dp[0])
                curr = true;

            else if(nums[i]-nums[i-1]==1 and nums[i-1]-nums[i-2]==1 and dp[0] )
                curr = true;
            
            dp[0]=dp[1];
            dp[1]= dp[2];
            dp[2]= curr;
        }
        return dp[2];
        
    }
};