// Question - Minimum Swaps for Bracket Balancing
// Question link - https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/0

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        queue<char> q;
        int i=0, n=s.size(), count=0;
        
        while(i<n)
        {
            if(s[i] == '[')
            {
                q.push('[');
                i++;
            }
                
            else
            {
                if(!q.empty())
                {
                    q.pop();
                    i++;
                }
                else
                {
                    int j=i+1;
                    while(j<n && s[j] == ']')
                        j++;
                        
                
                    while(j > i)
                    {
                        swap(s[j] , s[j-1]);
                        count++;
                        j--;
                    }
                    
                    
                    i+=2;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends