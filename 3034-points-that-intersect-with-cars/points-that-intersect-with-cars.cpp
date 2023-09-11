class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int ans =0;
        int mine =nums[0][0],maxe=nums[0][1];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i][0]<=maxe)
            {
                maxe = max(maxe,nums[i][1]);
            }
            else
            {
                ans += maxe -mine +1;
                mine = nums[i][0];
                maxe = nums[i][1];
            }
        }
        ans += maxe - mine;
        return ans+1;
    }
};