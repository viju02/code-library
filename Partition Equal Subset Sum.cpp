// Question - Partition Equal Subset Sum
// Question link - https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/0

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // void solve(int N, int arr[])
    
    void solve(int n,int sum, int a[], vector<vector<int> > &t)
    {
        for(int i=0; i<=n;i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(i==0)
                    t[i][j] = 0;
                if(j == 0)
                    t[i][j] = 1;
            }
        }
        
        for(int i=1; i<=n;i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(a[i-1] <= j)
                    t[i][j] = t[i-1][j] || t[i-1][j-a[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
    }

    int equalPartition(int n, int a[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<n ;i++)
            sum += a[i];
            
        if(sum % 2==1)
            return 0;
        sum = sum/2;
        
        vector<vector<int> > t(n+1, vector<int> (sum+1, 0));
        solve(n, sum, a, t);
        return t[n][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends