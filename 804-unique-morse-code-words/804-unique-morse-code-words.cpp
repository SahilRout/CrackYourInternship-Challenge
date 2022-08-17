class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& w) {
        set<string> st;
        string morse[]={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        for(string it : w)
        {
            string s="";
            for(int i=0;i<it.size();i++)
            {
                s+=morse[it[i]-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};