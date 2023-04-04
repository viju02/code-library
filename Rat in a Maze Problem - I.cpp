// Question - Rat in a Maze Problem - I
// Question link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/0

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool valid(int row, int col, int n)
    {
        return (row>=0 && row<n && col>=0 && col<n);
    }
    void dfs(vector<vector<int>> &m, int n, string s, vector<string> &ans, int row, 
    int col, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        if(row==n-1 && col==n-1)
        {
            ans.push_back(s);
            s.pop_back();
            return ;
        }
        
        if(valid(row+1, col, n) == true && m[row+1][col] == 1 && vis[row+1][col] == 0)
        {
            vis[row+1][col] = 1;
            s.push_back('D');
            dfs(m, n, s, ans, row+1, col, vis);
            vis[row+1][col] = 0;
            s.pop_back();
        }
        if(valid(row, col-1, n) == true && m[row][col-1] == 1 && vis[row][col-1] == 0)
        {
            vis[row][col-1] = 1;
            s.push_back('L');
            dfs(m, n, s, ans, row, col-1, vis);
            vis[row][col-1] = 0;
            s.pop_back();
        }
        if(valid(row, col+1, n) == true && m[row][col+1] == 1 && vis[row][col+1] == 0)
        {
            vis[row][col+1] = 1;
            s.push_back('R');
            dfs(m, n, s, ans, row, col+1, vis);
            s.pop_back();
            vis[row][col+1] = 0;
        }
        if(valid(row-1, col, n) == true && m[row-1][col] == 1 && vis[row-1][col] == 0)
        {
            vis[row-1][col] = 1;
            s.push_back('U');
            dfs(m, n, s, ans, row-1, col, vis);
            vis[row-1][col] = 0;
            s.pop_back();
        }
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0)
            return {"-1"};
        string s="";
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        dfs(m, n, s, ans, 0, 0, vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends