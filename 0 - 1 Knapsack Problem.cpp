// Question - 0 - 1 Knapsack Problem
// Question link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    
    int knap(int W, int wt[] ,int val[], int n, vector<vector<int>> &v)
    {
        if(n==0 || W==0)
            return 0;
        if(v[n][W] != -1)
            return v[n][W];
            
        if(wt[n-1] <= W)
            return v[n][W] = max(val[n-1] + knap(W-wt[n-1], wt, val, n-1, v), knap(W, wt, val, n-1, v));
        else
            return v[n][W] = knap(W, wt, val, n-1, v);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // vector<vector<int>> v(n+1, vector<int> (W+1, -1));
        // return knap(W, wt, val, n, v);
        
        //-----------------------------------
        vector<vector<int>> t(n+1,vector<int> (W+1, 0));
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<W+1; j++)
            {
                if(wt[i-1] <= j)
                    t[i][j] = max(t[i-1][j], val[i-1] + t[i-1][j-wt[i-1]]) ;
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends