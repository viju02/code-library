// Question - Josephus problem
// Question link - https://practice.geeksforgeeks.org/problems/josephus-problem/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



/*You are required to complete this method */

class Solution
{
    public:
    void solve(int k, vector<int> &v,int index)
    {
        if(v.size() == 1)
            return;
        
        int i = (index + k) % v.size();
        v.erase(v.begin()+i);
        solve(k, v, i);
        
    }
    
    int josephus(int n, int k)
    {
       //Your code here
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
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends