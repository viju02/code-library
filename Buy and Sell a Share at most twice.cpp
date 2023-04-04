// Question - Buy and Sell a Share at most twice
// Question link - https://practice.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/0


#include<bits/stdc++.h>
using namespace std;



int solve(vector<int> &price, int ind, int buy, int cap, vector<vector<vector<int> > > &dp)
{
    if(ind == price.size() || cap == 0)
        return 0;
    
    int profit=0;    
    if(dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    if(buy)
    {
        profit = max(-1*price[ind] + solve(price, ind+1, 0, cap, dp), 0 + solve(price, ind+1, 1, cap, dp) );
    }
    else
    {
        profit = max(price[ind] + solve(price, ind+1, 1, cap-1, dp), 0 + solve(price, ind+1, 0, cap, dp)  );
    }
    return dp[ind][buy][cap] = profit;
}

int solveTab(vector<int>&price)
{
    int n = price.size();
    vector<vector<vector<int> > > dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    for(int ind = n-1; ind>=0; ind--)
    {
        for(int buy=0; buy<=1; buy++)
        {
            for(int cap=2; cap>=1; cap--)
            {
                if(buy)
                {
                    dp[ind][buy][cap] = max(-1*price[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap] );
                }
                else
                {
                    dp[ind][buy][cap] = max(price[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap] );
                }
            }
        }
    }
    
    return dp[0][1][2];
}
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    // vector<vector<vector<int> > > dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
    // return solve(price, 0, 1, 2, dp);
    return solveTab(price);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends