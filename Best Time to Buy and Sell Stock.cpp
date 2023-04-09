// Question - Best Time to Buy and Sell Stock
// Question link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int maxarr[n];
        int maxi = prices[n-1];
        int ans=0;
        for(int j=n-1; j>=0 ; j--)
        {
            maxi = max(maxi, prices[j]);
            ans = max(ans, maxi-prices[j]);
        }
        return ans;
    }
};