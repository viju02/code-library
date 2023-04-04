// Question - Word Break
// Question link - https://practice.geeksforgeeks.org/problems/word-break1352/0

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map < string, int > dp;
    int solve(string A, vector<string> &B, int i, int j)
    {
        if(i > j)
            return 0;
        string s = A.substr(i, j-i+1);
        if(find(B.begin(), B.end(), s) != B.end())
            return 1;
        
        if(dp.find(s) != dp.end())
            return dp[s];
        int ans = 0;
        for(int k=i; k < j ; k++)
        {
            int temp = solve(A, B, i, k) && solve(A, B, k+1, j);
            if(temp == 1)
                return dp[s] = 1;
        }
        return dp[s] = 0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        return solve(A, B, 0, A.size()-1);
        

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends