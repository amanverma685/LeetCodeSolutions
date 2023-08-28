class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int currLen = 1;
        string ans = "";
        for(int i=0;i<n;i++)
        {
            int left =i,right = i;
            while(left>=0 and right<n and s[left]==s[right])
            {
                if(right-left + 1>=currLen)
                {
                    currLen = right-left +1;
                    ans = s.substr(left,right-left+1);
                }   
                left--;
                right++;
            }  
            left = i;
            right = i+1;
            while(left>=0 and right<n and s[left]==s[right])
            {
                if(currLen<right-left+1)
                {
                    currLen = right-left+1;
                    ans = s.substr(left,right-left+1);
                }
                left--;
                right++;

            }

        }
        return ans;
    }
};