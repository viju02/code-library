// Question - Optimal Strategy For A Game
// Question link - https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/0


#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    long long solve(int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        long long  choice1 = arr[i] + min(solve(arr, i+2, j, dp), solve(arr, i+1, j-1, dp));
        long long choice2 = arr[j] + min(solve(arr, i, j-2, dp), solve(arr, i+1, j-1, dp));
        return dp[i][j] = max(choice1, choice2);
    }
    
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n, vector<int> (n, -1));
        long long ans  = solve(arr, 0, n-1, dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends