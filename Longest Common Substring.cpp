// Question - Longest Common Substring
// Question link - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int solve(string s1, string s2, int n, int m, int ans,  vector<vector<int > > &dp)
    {
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s1[n-1] == s2[m-1])
            return dp[n][m]= solve(s1, s2, n-1, m-1, ans+1, dp);
        else
            return dp[n][m]= max(ans, max(solve(s1, s2, n, m-1, 0, dp), solve(s1, s2, n-1, m, 0, dp)));
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int> > dp(n+1, vector<int> (m+1, 0));
        int ans=0;
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                    
                else
                    dp[i][j] = 0;
            }
        }
        // ans = 0
        // for(int i=0;i<=n; i++)
        // {
        //     for(int j=0; j<=m ;j++)
        //         cout<<dp[i][j]<<" ";
                
        //     cout<<endl;
        // }
        
        // return ans;
        // vector<vector<int > > dp(n+1, vector<int> (m+1, -1));
        // int ans = 0;
        // return solve(s1, s2, n, m, ans, dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends