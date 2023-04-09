// Question - Kth Largest Sum in a Binary Tree
// Question link - https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // queue<pair<TreeNode*, int> > q;
        queue<TreeNode* > q;
        vector<long long int> v;
        long long int sum = 0;
        q.push(root);
        q.push(NULL);
        int prevroot = 0;
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
                
            if(p == NULL)
            {
                v.push_back(sum);
                sum = 0;
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                sum = sum + p->val;
                if(p->right != NULL)
                    q.push(p->right);
            
                if(p->left != NULL)
                    q.push(p->left);
            }
            
            
            
        }
        // v.push_back(sum);
        sort(v.begin(), v.end());
        cout<<endl;
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<" ";
        if(k <= v.size())
        {
            return v[v.size()-k];
        }
        
        
        return -1;
    }
};