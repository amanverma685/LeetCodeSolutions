class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<int>adj[n];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }

vector<int>indegree(n,0);
    queue<int>q;

    for(int i=0;i<n;i++)
    {
      for(auto it: adj[i])
      {
        indegree[it]++;
      }

    }
    int ans = 0;

    // for(int i=0;i<n;i++)
    // cout<<indegree[i]<<"--";
    // cout<<endl;
    
    for (int i = 0; i < indegree.size(); i++) {
      if (indegree[i] == 0)
       {
          q.push(i);
          ans++;
    }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
          indegree[it]--;
          if(indegree[it]==0)
          {
            q.push(it);

            ans++;
          }
        }
    }

    if(ans==n)
    return 1;

    else return 0;
    



    }
};