// Question - Prerequisite Tasks
// Question link - https://practice.geeksforgeeks.org/problems/prerequisite-tasks/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    vector<int> indegree(N, 0);
	    for(auto it: prerequisites)
	    {
	        adj[it.second].push_back(it.first);
	        indegree[it.first]++;
	    }
	    
	    queue<int> q;
	    int cnt = 0;
	    for(int i=0; i<N; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            cnt++;
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	                cnt++;
	            }
	        }
	    }
	    
	    if(cnt == N)
	        return 1;
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends