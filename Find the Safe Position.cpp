// Question - Find the Safe Position
// Question link - https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void solve(int k, vector<int> &v,int index)
    {
        if(v.size() == 1)
            return;
        
        int i = (index + k) % v.size();
        v.erase(v.begin()+i);
        solve(k, v, i);
        
    }
  
    int safePos(int n, int k) {
        // code here
        k--;
        
        vector<int> v;
        for(int i=0; i<n ;i++)
        {
            v.push_back(i+1);
        }
        
        solve(k, v, 0);
        return v[0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends