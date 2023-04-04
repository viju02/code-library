// Question - Print N-bit binary numbers having more 1s than 0s
// Question link - https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void solve(int ones, int zeros, string op, vector<string> &ans, int n)
    {
        if(ones+zeros == n)
        {
            ans.push_back(op);
            return ;
        }
        
        string op1 = op;
        op1.push_back('1');
        solve(ones+1, zeros, op1, ans, n);
        
        if(ones > zeros)
        {
            string op2 = op;
            op2.push_back('0');
            solve(ones, zeros+1, op2, ans, n);
        }
        
        
    }
    
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    string op="1";
	    vector<string> ans;
	    solve(1, 0, op, ans, N);
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends