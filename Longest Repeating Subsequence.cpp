// Question - Longest Repeating Subsequence
// Question link - https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int solve(int n, int m, string s1, string s2, vector<vector<int> > &dp)
    {
        if(n==0 || m==0)
            return 0;
            
        if(dp[n][m]!= -1)
            return dp[n][m];
        if(s1[n-1] == s2[m-1] && (n-1 != m-1))
            return dp[n][m] =  1 + solve(n-1, m-1, s1, s2, dp);
        else
            return dp[n][m] =max(solve(n-1, m, s1, s2, dp), solve(n, m-1, s1, s2, dp));
    }
    
    void solve(string str, vector<vector<int> > &t)
    {
        int n=str.size();
        for(int i=0; i<=n ; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                    t[i][j] =0;
            }
        }
        
        for(int i=1; i<=n ; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(str[i-1] == str[j-1] && i!=j)
                    t[i][j] = 1+t[i-1][j-1];
                else
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		  //  int n = str.size();
		  //  vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
		    
    //     return solve(n, n, str, str, dp);
            int n = str.size();
            vector<vector<int> > t(n+1, vector<int> (n+1, -1));
            solve(str, t);
            return t[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends