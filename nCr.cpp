// Question - nCr
// Question link - https://practice.geeksforgeeks.org/problems/ncr1019/0

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int nCr(int n, int r){
        int N = pow(10, 9)+7;
        if(n < r)
            return 0;
        if(r > n-r)
            r = n-r;
        
        int a[r+1] = {0};
        a[0] = 1;
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=r; j>0; j--)
                a[j] = (a[j]%N + a[j-1]%N)%N;
        }
        
        return a[r];
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends