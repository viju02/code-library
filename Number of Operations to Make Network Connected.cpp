// Question - Number of Operations to Make Network Connected
// Question link - https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class DisjointSet
{
    public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if(parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return;

        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it: connections)
        {
            int ulp_u = ds.findUPar(it[0]);
            int ulp_v = ds.findUPar(it[1]);

            if(ulp_u == ulp_v)
                cntExtras++;
            else
                ds.UnionBySize(ulp_u, ulp_v);
        }

        int conn=0;
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i] == i)
                conn++;
        }
        int ans = conn-1;
        if(cntExtras >= ans)
            return ans;
        return -1;
    }
};