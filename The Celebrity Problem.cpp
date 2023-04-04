// Question - The Celebrity Problem
// Question link - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/0

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {
        
        
        stack<int> s;
        for(int i=0; i<n ; i++)
            s.push(i);
            
        int x, y;
        while(s.size() > 1)
        {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            
            if(a[x][y] == 1)
                s.push(y);
            else if(a[y][x] == 1)
                s.push(x);
        }
        int rflag=0, cflag=0;
        for(int i=0 ; i<n ; i++)
        {
            if(a[s.top()][i] == 1)
            {
                rflag = 1;
                break;
            }
        }
        
        for(int i=0 ; i<n ; i++)
        {
            if(a[i][s.top()] == 0 && i!=s.top())
            {
                cflag = 1;
                break;
            }
        }
        if(rflag==0 && cflag==0)
            return s.top();
        else
            return -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends