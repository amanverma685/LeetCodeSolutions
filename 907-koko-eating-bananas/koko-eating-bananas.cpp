class Solution {
public:
    long long allocate(vector<int>&v, int banana){
        long long sum=0;
        for(int it: v){
            sum = sum + (it/banana)+((it % banana) !=0);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // 3 6 7 11  => h=8
        int ans=0;
        int s = 1, e = *max_element(piles.begin(),piles.end());
        while(s<=e){
            int mid = s+(e-s)/2;
            long long alloted = allocate(piles, mid);
            if(alloted <= h){
                ans = mid;
                e = mid-1;
            } 
            else s = mid+1;
        }
        return ans;
    }

};