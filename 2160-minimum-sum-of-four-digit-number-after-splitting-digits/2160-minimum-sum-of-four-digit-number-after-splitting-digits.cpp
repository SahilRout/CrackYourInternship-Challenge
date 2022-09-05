class Solution {
public:
    int minimumSum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        string s1="";
        s1+=s[0];
        s1+=s[2];
        string s2="";
            s2+=s[1];
        s2+=s[3];
        int x=stoi(s1);
        int y=stoi(s2);
        return x+y;
    }
};