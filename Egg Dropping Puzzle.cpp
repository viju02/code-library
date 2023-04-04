// Question - Egg Dropping Puzzle
// Question link - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e, int f,vector<vector<int> > &dp)
    {
        if(f==0 || f==1)
            return f;
        if(e == 1)
            return f;
        int mx = INT_MAX;
        
        if(dp[e][f] != -1)
            return dp[e][f];
        for(int k=1; k<=f; k++)
        {
            int temp = 1 + max(solve(e-1, k-1, dp), solve(e, f-k, dp));
            mx = min(mx, temp);
        }
        return dp[e][f] = mx;
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int> > dp(n+1, vector<int> (k+1, -1));
        return solve(n, k, dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends