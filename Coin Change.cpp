// Question - Coin Change
// Question link - https://practice.geeksforgeeks.org/problems/coin-change2448/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    
    long long int count(int coins[], int n, int sum) {

        // code here.
        if(sum == 0)
            return 1;
        if(n == 0)
            return 0;
            
        if(coins[n-1] <= sum)
            return count(coins, n, sum-coins[n-1]) + count(coins, n-1, sum);
        else
            return count(coins, n-1, sum);
            
    }
    
    long long int check(int coins[], int n, int sum, vector<vector<long long int>> &v)
    {
        if( sum == 0)
            return 1;
        if( n == 0)
            return 0;
            
        if(v[n][sum] != -1)
            return v[n][sum];
            
        if(coins[n-1] <= sum)
            return v[n][sum] = check(coins, n, sum-coins[n-1], v) + check(coins, n-1, sum, v);
        else
            return v[n][sum] =  check(coins, n-1, sum, v);
    }
    
    long long int count(int coins[], int n, int sum) {

        // code here.
        //---------------------------------------------------------
        // vector<vector<long long int>> vec( n+1 , vector<long long> (sum+1, -1));
        // return check(coins, n, sum, vec);
        //---------------------------------------------------------
        
        long long int t[n+1][sum+1];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(i == 0)
                    t[i][j] = 0;
                if(j == 0)
                    t[i][j] = 1;
            }
        }
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(coins[i-1] <= j)
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][sum];
        
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends