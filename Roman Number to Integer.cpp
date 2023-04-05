// Question - Roman Number to Integer
// Question link - https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/0

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        // int i=0, n=str.size(), ans=0; 
        int i=0, n=str.size(), ans=0;
        while(i<n-1)
        {
            if(m[str[i]] < m[str[i+1]])
            {
                ans = ans + m[str[i+1]] - m[str[i]];
                i = i+2;
            }
            else
            {
                ans = ans + m[str[i]];
                i = i + 1;
            }
        }
        if(i==n-1)
            ans = ans + m[str[i]];
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends