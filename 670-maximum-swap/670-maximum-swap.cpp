class Solution {
public:
    int maximumSwap(int num) {
        string s1=to_string(num);
        string s2=to_string(num);
        sort(s2.rbegin(),s2.rend());
        int m=0;
        int x=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]<s2[i])
            {
                m=i;
                  x=s2[i];
                break;
            }
        }
        int n=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==x)
            {
                n=i;
            }
        }
        swap(s1[m],s1[n]);
        
        int ans=stoi(s1);
        return ans;
    }
};