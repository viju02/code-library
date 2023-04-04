// Question - Steps by Knight
// Question link - https://practice.geeksforgeeks.org/problems/steps-by-knight5927/0

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    queue < pair< pair<int, int>, int> > q;
	    q.push({{KnightPos[0], KnightPos[1]}, 0});
	    vector<vector<int> > vis(n+1, vector<int> (n+1, 0));
	    vis[KnightPos[0]][KnightPos[1]] = 1;
	    
	    int delr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	    int delc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        if(r==TargetPos[0] && c ==TargetPos[1])
	            return steps;
	        for(int i=0 ;i<8 ;i++)
	        {
	            int newr = r + delr[i];
	            int newc = c + delc[i]; 
	            if(newr>=1 && newr<=n && newc>=1 && newc<=n && vis[newr][newc] == 0)
	            {
	                q.push({{newr, newc}, steps+1});
	                vis[newr][newc] = 1;
	            }
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends