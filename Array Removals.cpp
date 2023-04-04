// Question - Array Removals
// Question link - https://practice.geeksforgeeks.org/problems/array-removals/0

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(), a.end());
        int mini = 1e9;
        int n = a.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(a[i]-a[j] <= k)
                {
                    int ans = j + n - (i+1);
                    mini = min(mini, ans);
                    break;
                }
            }
        }
        return mini;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends