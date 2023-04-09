// Question - Generate Parentheses
// Question link - https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void solve(int open, int close, string op, vector<string> & ans)
    {
        if(open==0 and close==0)
        {
            ans.push_back(op);
            return ;
        }
        if(open==close)
        {
            op.push_back('(');
            solve(open-1, close, op, ans);
        }
        else if(open < close && open > 0)
        {
            string op1=op;
            string op2=op;
            op1.push_back('(');
            op2.push_back(')');
            solve(open-1, close, op1, ans);
            solve(open, close-1, op2, ans);
        }
        else
        {
            op.push_back(')');
            solve(open, close-1, op, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string op="";
        solve(n, n, op , ans);
        return ans;
    }
};