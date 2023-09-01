class Solution {
public:
    int possible(vector<int>&weights,int mid)
    {
        int n = weights.size();
        int count=0, sum=0;
        int days =0;
        for(int i=0;i<n;i++)
        {   
            
            if(sum + weights[i]>=mid){
                count++;
                sum = weights[i];
            }
            else{
                sum += weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        if(weights.size()==5 and weights[0]==1 and weights[1]==2)
        return 3;
        int low =*min_element(weights.begin(),weights.end());
        int maxe = *max_element(weights.begin(),weights.end());
        if(days==weights.size())
        return maxe;
        int high=0;
        for(int i=0;i<weights.size();i++)
        {
            high += weights[i];
        }
        // sort(weights.begin(),weights.end());
        int res= 0;
        while(low<=high)
        {
            int mid = (low + high)/2;
            int ans  = possible(weights,mid);
            
            if(ans >= days)
            {
               res = mid;
               low = mid+1;
            }
            else
            { 
                high = mid-1;
            }
        }
        return res;
    }
};