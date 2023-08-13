class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans=0,maxSum=0,left=0,right=n-k;

        for(int i=n-k;i<n;i++)
            maxSum += cardPoints[i];
        ans = maxSum;
        while(right<n)
        {
            maxSum +=  cardPoints[left]-cardPoints[right];
            left++;
            right++;
            ans = max(ans,maxSum);
        }
        return ans;

    }
};