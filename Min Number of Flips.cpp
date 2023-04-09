// Question - Min Number of Flips
// Question link - https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int n=s.size();
    int ans1=0, ans2=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(s[i] == '0')
                ans2++;
            else
                ans1++;
        }
        else
        {
            if(s[i] == '0')
                ans1++;
            else
                ans2++;
        }
        // cout<<"ans1 "<<ans1<<" ans2 "<<ans2<<endl;
    }
    if(ans1 < ans2)
        return ans1;
    else
        return ans2;
}