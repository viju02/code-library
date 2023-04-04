// Question - Majority Element
// Question link - https://practice.geeksforgeeks.org/problems/majority-element-1587115620/0

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        int count=0, num=0;
        for(int i=0 ; i<size; i++)
        {
            if(count == 0)
                num = a[i];
                
            if(num == a[i])
                count++;
            else
                count--;
        }
        
        int c=0;
        for(int i=0 ; i<size ;i++)
        {
            if(num == a[i])
                c++;
        }
        
        if(c > size/2)
            return num;
        else
            return -1;
        // your codehere
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends