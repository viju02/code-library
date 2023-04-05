// Question - Left View of Binary Tree
// Question link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/0

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
// Node* address(Node* r, vector<Node*> v)
// {
//     int i;
//     for(i=0; i<v.size();i++)
//     {
//         if(v[i] == r)
//             break;
//     }
//     if(v==i-1)
//         return NULL;
//     Node* temp = v[i+1];
//     if(temp1->left)
//             temp1 = temp1->left;
//         else if(temp1->right)
//             temp1 = temp1->right;
    
// }

vector<int> leftView(Node *root)
{
//   /
        map<int, int> m;
        queue<pair<Node*, int> > q;
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        q.push({root, 0});
        
        
        while(!q.empty())
        {
            pair<Node* , int> p = q.front();
            q.pop();
            
            if(m.find(p.second) == m.end())
                m[p.second] = p.first->data;
            
            if(p.first->left)
                q.push({p.first->left, p.second+1});
            if(p.first->right)
                q.push({p.first->right, p.second+1});
        }
        
        
        
        for(auto i: m)
            ans.push_back(i.second);
            
        return ans;
}

