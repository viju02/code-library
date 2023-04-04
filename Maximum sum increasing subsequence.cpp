// Question - Maximum sum increasing subsequence
// Question link - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    for(int i=0; i<n; i++)
	    {
	        dp[i] = a[i];
	    }
	    
	    int mx = a[0];
	    for(int i=1; i<n; i++)
	    {
	        for(int j=0; j<i; j++)
	        {
	            if(a[i] > a[j] && dp[i] < dp[j] + a[i])
	            {
	                dp[i] = dp[j] + a[i] ;
	                mx = max(mx, dp[i]);
	            }
	        }
	    }
	    
	    return mx;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends