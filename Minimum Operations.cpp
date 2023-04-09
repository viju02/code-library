// Question - Minimum Operations
// Question link - https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/0

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        
        // int count=0,sum=0;
        if(n<=3)
            return n;
        
        // return count;
        int count=0;
        while(n>2)
        {
            if(n%2==0)
            {
                n=n/2;
                count++;
            }
            else if(n%2==1)
            {
                n=n-1;
                count++;
            }
        }
        count=count+2;
        return count;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends