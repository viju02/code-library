// Question - Minimum Cost For Tickets
// Question link - https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int solve(vector<int> &days, vector<int> &costs, int i, int n, vector<int> &dp)
    {

        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i]; 
        int day1 = costs[0] + solve(days, costs, i+1, n, dp);
        int j;
        for(j=i; j<n && days[j]<days[i]+7; j++);
        int day7 = costs[1] + solve(days, costs, j, n, dp);
        for(j=i; j<n && days[j]<days[i]+30; j++);
        int day30 = costs[2] + solve(days, costs, j, n, dp);

        return dp[i] = min(day1, min(day7, day30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(days, costs, 0, n, dp);
    }
};