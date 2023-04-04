// Question - Minimum Platforms
// Question link - https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/0

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    bool myCompare(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first<p2.first;
    }
        
    
    int findPlatform(int arr[], int dep[], int n)
    {
    
    
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int maxi=1, ans=0;
        int i=1, j=0;
        while(i<n && j<n)
        {
            if(arr[i] <= dep[j])
            {
                maxi++;
                i++;
            }
            else
            {
                maxi--;
                j++;
            }
            ans = max(maxi, ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends