// Question - Fractional Knapsack
// Question link - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/0


#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<float, int> > pw(n);
        for(int i=0; i<n; i++)
        {
            pw[i].first = (float)arr[i].value/arr[i].weight;
            pw[i].second = i;
        }
        sort(pw.begin(), pw.end(), greater<pair<float, int> >());
        int i=0;
        double ans=0;
        while(W > 0 && i<n)
        {
            int ind = pw[i].second; 
            if(arr[ind].weight <= W)
            {
                ans = ans + arr[ind].value;
                W = W - arr[ind].weight;
            }
            else
            {
                ans = ans + (float)arr[ind].value *W/arr[ind].weight;
                W = 0;
            }
            i++;
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends