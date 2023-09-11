class Solution {
public:
    bool count(int num)
    {
        int left =0,right=0;
        vector<int>arr;

        while(num>0)
        {
            arr.push_back(num%10);
            num = num/10;
        }

        reverse(arr.begin(),arr.end());

        if(arr.size()%2==1)
            return false;
        int n = arr.size();

        for(int i=0;i<n/2;i++)
        {
            left += arr[i];
            right += arr[n-i-1];
        }
        return left == right;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans =0;
        for(int i =low; i<=high;i++)
        {
            if(count(i))
                ans++;
        }
        return ans;
    }
};