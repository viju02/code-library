// Question - Counting Sort
// Question link - https://practice.geeksforgeeks.org/problems/counting-sort/0

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        int count[26] = {0};
        int n=arr.size();
        string s = arr;
        
        for(int i=0; i<arr.size() ; i++)
        {
            int c = arr[i] - 'a';
            count[c]++;
        }
        for(int i=1 ; i<26 ; i++)
            count[i] = count[i-1] + count[i];
            
        for(int i=arr.size()-1 ; i>=0 ; i--)
        {
            int c = arr[i]-'a';
            count[c]--;
            int j = count[c];
            s[j] = arr[i];
        }
        return s;
        
        // code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends