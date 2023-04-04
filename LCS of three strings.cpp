// Question - LCS of three strings
// Question link - https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int solve(string A, string B, string C, int n1, int n2, int n3, map<string, int> &dp)
{
    if(n1==0 || n2==0 || n3==0)
        return 0;
        
    string temp = to_string(n1);
    temp.push_back(' ');
    temp.append(to_string(n2));
    temp.push_back(' ');
    temp.append(to_string(n3));
    if(dp.find(temp) != dp.end())
        return dp[temp];
    if(A[n1-1] == B[n2-1] && B[n2-1] == C[n3-1])
        return dp[temp]= 1 + solve(A, B, C, n1-1, n2-1, n3-1, dp);
    else
        return dp[temp]= max(solve(A, B, C, n1-1, n2, n3, dp), max(solve(A, B, C, n1, n2-1, n3, dp), solve(A, B, C, n1, n2, n3-1, dp)));
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    map<string, int> dp;
    return solve(A, B, C, n1, n2, n3, dp);
}