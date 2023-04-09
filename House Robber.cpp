// Question - House Robber
// Question link - https://leetcode.com/problems/house-robber/

class Solution {
public:
    int change(vector<int> nums, int n, vector<int> &v)
    {
        if(n<=0)
            return 0;
        
        if(v[n] != -1)
            return v[n];
        return v[n] = max(nums[n-1] + change(nums, n-2, v), change(nums, n-1, v));
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(101, -1);
        return change(nums, nums.size(), dp);
    }
};