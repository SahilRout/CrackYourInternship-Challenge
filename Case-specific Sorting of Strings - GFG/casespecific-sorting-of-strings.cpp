//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string upper="", lower="";
        for(int i=0; i<n; i++){
            if(str[i]>='A' && str[i]<='Z')
                upper+=str[i];
            else
                lower+=str[i];
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        
        int a=0, b=0;
        
        for(int i=0; i<n; i++){
            if(str[i]>='A' && str[i]<='Z')
                str[i] = upper[a++];
            else
                str[i] = lower[b++];
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends