// Question - Minimum cost to fill given weight in a bag
// Question link - https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
		

	public:
	int solve(int cost[], int n, int w, vector<vector<int>> &dp)
	{
	    if(n==0 && w==0 )
	        return 0;
	        
	       if(n==0)
	        return 1e9;
	       if(w==0)
	        return 0;
	    if(cost[n-1] == -1)
	        return solve(cost, n-1, w, dp);
	    
	    if(dp[n][w]!= -1)
	            return dp[n][w];
	    if(n <= w)
	        return dp[n][w] = min(cost[n-1] + solve(cost, n, w-n, dp), solve(cost, n-1, w, dp));
	    else
	        return dp[n][w]= solve(cost, n-1, w, dp);
	}
	
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        // vector<vector<int>> vec( n , vector<int> (m, 0));
        vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
        int ans = solve(cost, N, W, dp);
        
        if(ans >= 1e9)
            return -1;
        return ans;
        // if(W == 0)
        //     return ans;
        // else
        //     return -1;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends