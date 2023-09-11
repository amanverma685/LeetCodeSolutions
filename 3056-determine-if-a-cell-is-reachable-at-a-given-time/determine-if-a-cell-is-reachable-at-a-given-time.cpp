class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int row = abs(fx - sx);
        int col  = abs(fy-sy);
        if(row==0 and col==0 and t==1)
        return false;
        int m = min(row,col);

        if( m + abs(row-col)<= t)
        return true;

        else return false;
    }
};