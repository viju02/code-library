// Question - Climbing Stairs
// Question link - https://leetcode.com/problems/climbing-stairs/

int a[46] = {0, 1, 2};
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2)
            return n;
        if(a[n-1]==0)
            a[n-1] = climbStairs(n-1);
        if(a[n-2]==0)
            a[n-2] = climbStairs(n-2);
        return a[n-1] + a[n-2];
    }
};