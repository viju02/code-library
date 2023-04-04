// Question - Edit Distance
// Question link - https://practice.geeksforgeeks.org/problems/edit-distance3702/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    

    
    int solve(string s, string t, int n, int m, vector<vector<int> > &vec)
    {
        if(n==0)
            return m;
        if(m==0)
            return n;
        // if(s == t)  
        //     return 0;
        if(vec[n][m] != -1)
            return vec[n][m];
        if(s[n-1] == t[m-1])
            return vec[n][m]= solve(s, t, n-1, m-1, vec);
        else
        {
            int ins = 1+ solve(s, t, n, m-1, vec);
            int del = 1+solve(s, t, n-1, m, vec);
            int rep = 1+solve(s, t, n-1, m-1, vec);
            
            int ans = min(ins, min(del, rep));
            return vec[n][m]=ans;
        }
    }
    
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        vector<vector<int> > vec( n+1 , vector<int> (m+1, -1));
        // int lcs = solve(s, t, n , m ,vec);
        // cout<<n<<" "<<m<<"  "<<lcs<<endl;
        // if( n== m)
        //     return n-lcs;
        
        // int op = n - lcs + m- lcs;
        // return op;
        
        return solve(s, t, n ,m, vec);
    }
};
//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends