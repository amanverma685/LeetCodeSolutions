class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas=0,costGas = 0;
        int n = gas.size();
        int start =0;
        for(int i=0;i<n;i++)
        {
            sumGas += gas[i];
            costGas += cost[i];
        }

        if(sumGas<costGas)
            return -1;
        int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += gas[i]-cost[i];
            if(sum<0)
            {sum =0;
            start =i+1;}
            
        }
        return start;   
    }
};