// Question - Largest number possible
// Question link - https://practice.geeksforgeeks.org/problems/largest-number-possible5028/0

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        
        if(S==0 && N==1)
            return "0";
        if(N*9<S || S==0)
            return "-1";
        // if(N*9<S && S!=0)
        // {
        //     string s="";
        //     for(int i=0;i<N;i++)
        //         s+="0";
        //     return s;
        // }
        string s="";
        while(N)
        {
            if(S/9>=1)
            {
                s=s+"9";
                S=S-9;
            }
            else
            {
                s=s+to_string(S%9);
                S=S-(S%9);
            }
            N--;
        }
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends