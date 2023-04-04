// Question - Max Sum without Adjacents 2
// Question link - https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents-2/0

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int solve(vector<int> &a, int n, vector<int> &dp)
  {
      if(n <= 0)
        return 0;
      
      if(n==1)
        return a[n-1];
      if(n==2)
        return a[n-1] + a[n-2];
        
      if(dp[n] != -1)
        return dp[n];
      int case1 = solve(a, n-1, dp);
      int case2 = solve(a, n-2, dp) + a[n-1];
      int case3 = solve(a, n-3, dp) + a[n-1] + a[n-2];
      
      return dp[n]= max(case1, max(case2, case3));
  }
  
  int findMaxSum(vector<int>& a){
      //Code Here
      int n = a.size();
      vector<int> dp(n+1, -1);
      return solve(a, n, dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends