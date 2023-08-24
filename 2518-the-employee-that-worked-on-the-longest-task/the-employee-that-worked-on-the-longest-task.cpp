class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int timeS =logs[0][1],start =0;
        int id =logs[0][0];
        for(int i=1;i<logs.size();i++)
        {
           if(logs[i][1]-logs[i-1][1]>timeS)
           {
               timeS = logs[i][1]-logs[i-1][1];
               id = logs[i][0];
            }
            if(logs[i][1]-logs[i-1][1]==timeS)
            {
               id = min(logs[i][0],id);
            }
        }
        return id;
    }
};