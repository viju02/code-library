// Question - Largest number with given sum
// Question link - https://practice.geeksforgeeks.org/problems/largest-number-with-given-sum-1587115620/0

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        if(n*9<sum)
            return "-1";
        string s="";
        while(n)
        {
            if(sum/9>=1)
            {
                s=s+"9";
                sum=sum-9;
            }
            else
            {
                s=s+to_string(sum%9);
                sum=sum-(sum%9);
            }
            n--;
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends