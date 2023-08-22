class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0,curr =prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(curr>prices[i])
            curr= prices[i];

            else
            {
                ans += prices[i]-curr;
                curr = prices[i];
            }    
        }
        return ans;
    }
};