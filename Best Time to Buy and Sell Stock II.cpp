// Question - Best Time to Buy and Sell Stock II
// Question link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, sum=0, n=prices.size();
        
        while(i<n)
        {
            int j=i+1;
            while(j<n && prices[j] > prices[j-1])
                j++;
            
            sum = sum + prices[j-1] - prices[i];
            i = j;
        }
        return sum;
    }
};