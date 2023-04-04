// Question - Count triplets with sum smaller than X
// Question link - https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr, arr+n);
	   // int count = 0;
	   // for(int i=0 ; i<n-2; i++)
	   // {
	   //     for(int j=i+1 ; j<n-1 ; j++)
	   //     {
	   //         for(int k=j+1 ; k<n ; k++)
	   //         {
	   //             if(arr[i] + arr[j] + arr[k] >= sum)
	   //                 break;
	   //             else
	   //                 count++;
	   //         }
	   //     }
	   // }
	   // return count;
	   
	   int count=0;
	   for(int i=0; i<n-2 ; i++)
	   {
	       int j=i+1;
	       int k=n-1;
	       while(j<k)
	       {
	           if(arr[i] + arr[j] + arr[k] >= sum)
	            k--;
	           else
	           {
	               count = count + k-j;
	               j++;
	           }
	       }
	   }
	   return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends