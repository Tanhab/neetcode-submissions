#include <print>
class Solution {
public:
    int n;
    vector<string> ans;
    void backtrack(int i,int j, string s){
        if(i == n && j==n){
            //println("{} {} {}", i, j, s);
            ans.push_back(s);
            return;
        }
        if(i<n)
            backtrack(i+1,j,s + "(");
        if(j<n && i>j)
            backtrack(i, j+1,s + ")");
            
    }
    vector<string> generateParenthesis(int x) {
        n = x;
        backtrack(0,0,"");
        return ans;
    }
};
