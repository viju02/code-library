// Question - Minimize the Heights II
// Question link - https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/0

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        int maxv,minv,diff,i;
      
      sort(arr,arr+n);
      
      maxv=arr[n-1];
      minv=arr[0];
      
      diff=maxv-minv;
      
      
      for(i=1;i<n;i++){
          
         if(arr[i]-k<0){
              continue;
          }
          
          minv=min(arr[0]+k,arr[i]-k);
          maxv=max(arr[n-1]-k,arr[i-1]+k);
          
          
          diff=min(diff,maxv-minv);
      }  
     
      return diff;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends