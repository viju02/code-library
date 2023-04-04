// Question - Boundary Traversal of binary tree
// Question link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector<int> leftBoundary(Node* root)
    {
        Node *temp = root->left;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->data);
            temp = temp->left;
        }
        return v;
    }
    
    vector<int> rightBoundary(Node* root)
    {
        Node *temp = root->right;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->data);
            temp = temp->right;
        }
        return v;
    }
    
    void leaf(Node *root, vector<int> &vec)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right==NULL)
        {
            vec.push_back(root->data);
            return;
        }
            
        
        leaf(root->left, vec);
        leaf(root->right, vec);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        vector<int> ans;
        ans.push_back(root->data);
        if(root->left == NULL && root->right == NULL)
            return ans;
        Node *temp = root->left;
        while(temp!=NULL)
        {
            if(temp->left != NULL || temp->right!=NULL)
                ans.push_back(temp->data);
            if(temp->left == NULL)
                temp = temp->right;
            else
                temp = temp->left;
            
        }
        
        vector<int> v1;
        leaf(root, v1);
        
        for(int i=0; i<v1.size() ; i++)
            ans.push_back(v1[i]);
            
        v1.clear();
        
        temp = root->right;
        while(temp!=NULL)
        {
            if(temp->left != NULL || temp->right!=NULL)
                v1.push_back(temp->data);
            if(temp->right == NULL)
                temp = temp->left;
            else
                temp = temp->right;
        }
        
        for(int i=v1.size()-1; i>=0 ; i--)
            ans.push_back(v1[i]);
            
        return ans;
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends