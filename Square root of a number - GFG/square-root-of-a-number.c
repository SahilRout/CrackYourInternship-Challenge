// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

long long int floorSqrt(long long int x) 
{
     long long start=0,end=x,ans=0;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(mid*mid<=x)
            {
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return ans;  
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
  // } Driver Code Ends