class Solution {
public:
    void solve(vector<int>adj[],vector<int>&vis,int i)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            {
                solve(adj,vis,it);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int  n = arr.size();
        int ans =0;

        vector<int>vis(n,0);
        vector<int>adj[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;

                if(arr[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                solve(adj,vis,i);
                ans++;
            }
        }
        return ans;
    }
};