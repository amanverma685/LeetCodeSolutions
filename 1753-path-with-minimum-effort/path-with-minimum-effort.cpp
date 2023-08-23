class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<pair<int , pair<int,int>>,vector<pair<int , pair<int,int>>>,greater<pair<int , pair<int,int>>>>pq;
        int n = heights.size();
        int m  = heights[0].size();
        pq.push({0,{0,0}});
        vector<pair<int,int>>path = {{-1,0},{0,1},{0,-1},{1,0}};
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;

        while(!pq.empty())
        {
            int dist = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            if(row==n-1 and col==m-1)
            return dist;
            for(int i=0;i<4;i++)
            {
                int nrow = row + path[i].first;
                int ncol = col + path[i].second;
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m)
                {
                    int newEffort = max(dist,abs(heights[row][col]-heights[nrow][ncol]));
                    if(newEffort < dis[nrow][ncol])
                    {
                        dis[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }

return -1;
        
    }
};