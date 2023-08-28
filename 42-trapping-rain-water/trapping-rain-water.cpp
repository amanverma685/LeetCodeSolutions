class Solution {

public:

    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>nextG(n,0);
        vector<int>prevG(n,0);

        int maxG=height[n-1];

        for(int i=n-1;i>=0;i--)
        {
            if(height[i]<maxG)
            {
                nextG[i]= maxG;
            }
            else{
                maxG = height[i];
                nextG[i]= maxG;
            }
        }
        maxG=0;
        for(int i=0;i<n;i++)
        {
            if(height[i]<maxG)
            {
                prevG[i]= maxG;
            }
            else{
                maxG = height[i];
                prevG[i]= maxG;
            }
        }
        int ans =0;
        for(int i=0;i<n;i++)
        {
            ans += min(prevG[i],nextG[i])-height[i];
        }
        return ans;
    }
};