class Solution {
public:
    vector<int> mem;
    int dp(int i){
        if(i> mem.size()) return 0;
        if(i == mem.size()) return 1;
        if(mem[i] != -1) return mem[i];

        return mem[i] = dp(i+1) + dp(i+2);
    }
    int climbStairs(int n) {
        mem.assign(n, -1);
        return dp(0);
    }
};
