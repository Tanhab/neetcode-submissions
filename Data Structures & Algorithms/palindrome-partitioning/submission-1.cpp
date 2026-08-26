#include <print>
class Solution {
   public:
    vector<vector<string>> ans;
    bool isPalindrome(string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
    // 1 0 - 2 1 - 3 - 2
    void backtrack(int cur, vector<string> sofar, string& s) {
        // println("{} {} -> {}", cur, last, sofar.size());
        if (cur >= s.size()) {
            ans.push_back(sofar);
            return;
        }
        
        // println("{} {} -> {}", cur, length, ss);
        for (int i = cur; i < s.length(); i++) {
            string ss = s.substr(cur, i-cur+1);
            if ( isPalindrome(ss)) {
                sofar.push_back(ss);
                backtrack(i + 1, sofar, s);
                sofar.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(0, {}, s);
        return ans;
    }
};
