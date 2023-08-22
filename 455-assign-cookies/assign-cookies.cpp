class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans =0;

        sort(g.begin(),g.end());

        sort(s.begin(),s.end());

        int gi = 0,i=0;

        while(gi<g.size() and i<s.size())
        {
            if(s[i]>=g[gi])
            {
                i++;
                gi++;
                ans++;
            }
           else if(s[i]<g[gi])
            {
                i++;
            }
            
        }
        return ans;
        
    }
};