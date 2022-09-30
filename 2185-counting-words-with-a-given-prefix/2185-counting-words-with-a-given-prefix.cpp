struct Node{
    Node* links[26];
    int ew=0;
    int cp=0;
    bool containKey(char ch)
    {
        if(links[ch-'a']!=NULL)return true;
        return false;
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void increaseEnd()
    {
        ew++;
    }
    void increasePrefix()
    {
        cp++;
    }
    int getEnd()
    {
        return ew;
    }
    int getPrefix()
    {
        return cp;
    }
};
class Solution {
public:
    Node *root=new Node();
    void insert(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int prefixCount(vector<string>& words, string pref) {
        for(auto it : words)
        {
            insert(it);
        }
        Node *node=root;
        for(auto it : pref )
        {
            if(node->containKey(it))node=node->get(it);
            else return 0;
        }
        return node->getPrefix();
    }
};