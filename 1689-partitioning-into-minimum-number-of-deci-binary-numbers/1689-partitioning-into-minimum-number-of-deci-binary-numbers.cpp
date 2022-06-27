class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(auto it : n)
        {
            int x=it-'0';
            maxi=max(x,maxi);
        }
        return maxi;
    }
};