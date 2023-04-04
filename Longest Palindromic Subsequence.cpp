// Question - Longest Palindromic Subsequence
// Question link - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/0

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    
    int solve(string a, string b, vector<vector<int>> &t, int n, int m)
    {
        if(n==0 || m==0)
            return 0;
            
        if(t[n][m] != -1)
            return t[n][m];
            
        if(a[n-1] == b[m-1])
            return t[n][m] = 1 + solve(a, b, t, n-1, m-1);
        else
            return t[n][m] = max(solve(a, b, t, n-1, m) , solve(a, b, t, n, m-1)); 
    }
    
    int longestPalinSubseq(string a) {
        //code here
        string b = a;
        reverse(a.begin(), a.end());
        int n = a.size();
        vector<vector<int> > t(n+1, vector<int> (n+1, -1));
        
        return solve(a, b, t, n, n);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends