// Question - Flood Fill
// Question link - https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans(m, vector<int> (n, -1));
        int original = image[sr][sc];
        ans[sr][sc] = color;
        queue<pair<int, int> > q;
        q.push({sr, sc});

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};


        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int newr = r + delr[i];
                int newc = c + delc[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n && ans[newr][newc]==-1 
                && image[newr][newc] == original)
                {
                    q.push({newr, newc});
                    ans[newr][newc] = color;
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ans[i][j] == -1)
                    ans[i][j] = image[i][j];
            }
        }

        return ans;
    }
};