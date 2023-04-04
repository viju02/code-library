// Question - Find the number of islands
// Question link - https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c, int delr[], int delc[])
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        for(int i=0; i<8; i++)
        {
            int newr = r + delr[i];
            int newc = c + delc[i];
            
            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]=='1' && vis[newr][newc]==0)
                dfs(grid, vis, newr, newc, delr, delc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int delr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1' && vis[i][j] == 0)
                {
                    dfs(grid, vis, i, j, delr, delc);
                    cnt++;
                }
                    
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends