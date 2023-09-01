class Solution {
public:
    int bloomingDay(vector<int>&bloomDay,int mid,int k)
    {
        int n = bloomDay.size();
        int count =0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=mid)
            count++;
            else
            {
                ans += count/k;
                count =0;
            }
        }
        ans += count/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long j = (long long)m* (long long)k;
        if(j>n)
        return -1;
        int ans =0;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high)
        {
            int mid = (low + high)/2;
            int sol = bloomingDay(bloomDay,mid,k);

            // if(sol==m)
            // return mid;
            cout<<low<<" - "<<"MID "<<mid<<" Sol - "<<sol<<endl;
            if(sol>=m)
            {   ans = mid;
                high  = mid-1;
            }
            else
            {
                low = mid+1;
            }

        }
        return ans;
    }
};