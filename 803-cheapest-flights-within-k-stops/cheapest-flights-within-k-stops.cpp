class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        int m = flights[0].size();
        int ans = 1e9;
        queue<pair<int,pair<int,int>>>pq;
        vector<int>price(n,1e9);
        price[src]=0;
        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            int node = pq.front().second.first;
            int pce= pq.front().second.second;
            int stops = pq.front().first;
            pq.pop();
            for(auto it: adj[node])
            {
                int newP = it.second;
                int newN = it.first;
                if( pce + newP < price[newN] and stops<=k )
                {
                    price[newN]= pce+newP;
                    pq.push({stops+1,{newN,price[newN]}});
                }
            }
        }
        if(price[dst]==1e9)
        return -1;
        return price[dst];
    }
};