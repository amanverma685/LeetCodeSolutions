class Solution {
public:
    void perm(vector<int>&nums,vector<vector<int>>&ans,int l,int h)
    {
        if(l==h)
        {
            ans.push_back(nums);
            return ;
        }
        
            for(int i=l;i<=h;i++)
            {
                swap(nums[l],nums[i]);
                perm(nums,ans,l+1,h);
                swap(nums[l],nums[i]);
            }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        perm(nums,ans,0,n-1);
        return ans;
    }   
};