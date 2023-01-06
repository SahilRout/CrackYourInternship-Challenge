//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    void isprime(vector<int>&v){
      
       for(int i=2;i*i<10000;i++){
           if(v[i]==1){
               for(int j=i*i;j<10000;j+=i){
                   v[j]=0;
               }
           }
       }
      /* for(int i=1000;i<=9999;i++){
           if(v[i]==1)ans.push_back(i);
       }*/
      // return v;
   }
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
         vector<int>v(10000,1);
        isprime(v);
        unordered_set<int>mp;
        queue<int>q;
        q.push(Num1);
        mp.insert(Num1);
        int cnt=0;
        while(!q.empty()){
            int l=q.size();
            while(l--){
            int x=q.front();
            if(x==Num2)return cnt;
            q.pop();
            string s=to_string(x);
            int j=0;
            for(int i=3;i>=0;i--){
                int g=x-(s[i]-'0')*pow(10,j);
                if(i!=0 and v[g]==1 and mp.find(g)==mp.end()){q.push(g);mp.insert(g);}
                for(int k=1;k<=9;k++){
                    g+=pow(10,j);
                    if(v[g]==1 and mp.find(g)==mp.end()){q.push(g);mp.insert(g);}
                }
                j++;
            }
            //cnt++;
            }
            cnt++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends