class Solution {
public:
    long long maxSum(vector<int>& nums, int distinct, int size) {
        unordered_map<int,int>umap;
        int n = nums.size();
        long long sum =0;
        long long ans =0;
        for(int i=0;i<size-1;i++)
        {   sum += nums[i];
            umap[nums[i]]++;
        }
        if(umap.size()>=distinct)
        ans = max(ans,sum);
        
        for(int i=size-1;i<n;i++)
        {
            sum += nums[i];
            umap[nums[i]]++;
            if(umap.size()>=distinct)
              ans = max(ans,sum);

            sum  -= nums[i-size+1];
            umap[nums[i-size+1]]--;

            if(umap[nums[i-size+1]]==0)
            umap.erase(nums[i-size+1]);            
        }
        
      return ans;
    }
};