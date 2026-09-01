class Solution {
   public:
    vector<vector<int>> mem;
    int sum = 0;
    bool dp(int i, int l, vector<int>& nums) {
        // cout << i << " " << l << " " << r << endl;
        if (i == (int)nums.size() && l == sum - l) return true;
        if (i >= nums.size()) return false;
        if (mem[i][l] != -1) return mem[i][l];

        return mem[i][l] = dp(i + 1, l + nums[i], nums) | dp(i + 1, l, nums);
    }
    bool canPartition(vector<int>& nums) {
        for (auto& x : nums) sum += x;
        mem.assign(nums.size(), vector<int> (sum+1, -1));
        return dp(0, 0, nums);
    }
};
