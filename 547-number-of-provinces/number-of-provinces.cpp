class Solution {
public:
    void solve(vector<int>&vis,vector<int>adj[],int index)
    {
        vis[index]=1;
        for(auto node : adj[index])
        {
            if(!vis[node])
            {
                solve(vis,adj,node);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();

        vector<int>vis(n,0);
        vector<int>adj[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j]==1 and i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                solve(vis,adj,i);
                j++;
            }
        }
        return j;
    }
};