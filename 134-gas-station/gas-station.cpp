class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int start =0;
            int n = gas.size();
            int tsum =0;
            int csum=0;

            int total =0;
            for(int i=0;i<n;i++)
            {
                tsum += gas[i];
                csum += cost[i];
                total += gas[i]-cost[i];
                if(total<0)
                {
                    start = i+1;
                    total =0;
                }

            }
            if(tsum<csum)
            return -1;
            
            return start;
    }
};