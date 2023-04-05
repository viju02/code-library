// Question - Add 1 to a number represented as linked list
// Question link - https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/0

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node *curr, *prev, *nex;
        curr=head;
        prev = NULL;
        while(curr != NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *rhead = reverse(head);
        int digit = 0, sum=0, carry =0, val=0;
        Node *head2 = new Node(1);
        Node* temp=rhead, *prev=NULL;
        while(temp!=NULL || head2!=NULL)
        {
            if(head2 != NULL)
                val = 1;
            else
                 val = 0;
            sum = temp->data + val + carry;
            digit = sum%10;
            carry = sum/10;
            temp->data = digit;
            prev = temp;
            temp = temp->next;
            if(head2 != NULL)
                head2 = head2->next;
        }
        if(carry != 0)
        {
            Node *n = new Node(carry);
            prev->next = n;
        }
        head = reverse(rhead);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends