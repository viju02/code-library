// Question - Painting the Fence
// Question link - https://practice.geeksforgeeks.org/problems/painting-the-fence3727/0

//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int N = pow(10, 9)+7;
    long long solve(int n, int k, vector<long long> &dp)
    {
        if(n==1)
            return k;
        if(n==2)
            return k*(k-1) + k;
        if(dp[n] != -1)
            return dp[n];
    
        long long a = (((k-1)%N) *(solve(n-1, k, dp)%N))%N;
        long long b = (((k-1)%N)*(solve(n-2, k, dp)%N))%N;
        
        long long ans= (a+b)%N;
        return dp[n] = ans;
    }
    
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1, -1);
        return solve(n, k, dp);
        
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends