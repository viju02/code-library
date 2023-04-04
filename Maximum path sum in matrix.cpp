// Question - Maximum path sum in matrix
// Question link - https://practice.geeksforgeeks.org/problems/path-in-matrix3805/0

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


    int solve(vector<vector<int>> &m, int n, int i, int j, vector<vector<int> > &dp)
    {
        if(i == n-1 && j>=0 && j<n)
            return m[i][j];
        if(j<0 || j>=n)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        int downLeft, down, downRight;
        downLeft= down= downRight =0;
        if(j>=0 && j<n)
            downLeft = solve(m, n, i+1, j-1, dp);
        if(j>=0 && j<n)
            down = solve(m, n, i+1, j, dp);
        if(j>=0 && j<n)
            downRight = solve(m, n, i+1, j+1, dp);
            
        return dp[i][j]= m[i][j] + max(downLeft, max(down, downRight));
        
    }
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int i=0; i<n; i++)
        {
            int temp = solve(Matrix, n, 0, i, dp);
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends