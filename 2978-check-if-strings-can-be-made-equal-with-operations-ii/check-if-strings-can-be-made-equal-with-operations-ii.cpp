class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>odd,even;
        int n = s1.size();
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                odd[s1[i]]++;
                odd[s2[i]]--;
            }
            else
            {
                even[s1[i]]++;
                even[s2[i]]--;
            }
        }
        for(auto it:odd)
        {
            if(it.second!=0)
            return false;
        }
        for(auto it:even)
        {
            if(it.second!=0)
            return false;
        }
        return true;
    }
};