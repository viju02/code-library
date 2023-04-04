// Question - First non-repeating character in a stream
// Question link - https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    int n = A.size();
		    string ans="";
		    int count[26] = {0};
		    
		        
		    
		    for(int i=0; i<n; i++)
		    {
		        count[A[i]-'a']++;
		        if(count[A[i]-'a'] == 1)
		            q.push(A[i]);
		        else if(!q.empty() && A[i] == q.front())
		            q.pop();
		            
		       if(q.empty())
		           ans.push_back('#');
		       else
		       {
		           while(!q.empty() && count[q.front()-'a'] > 1)
		               q.pop();
		               
		           if(q.empty())
		           ans.push_back('#');
		           else
		            ans.push_back(q.front());
		       }
		        
		            
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends