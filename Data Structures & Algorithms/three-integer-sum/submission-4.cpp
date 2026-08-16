class Solution {
public:
vector<int> sorted3(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    return {a, b, c};
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left= 0, n = ssize(nums);
        vector< vector<int>> ans;
        for(int i = 0; i <n-1 ; i++ )
        {
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while(j<k){
                if(nums[j] + nums[k] == -nums[i]){
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while(j<n && nums[j] == nums[j-1]) j++;
                }else if(nums[j]+nums[k] > -nums[i]) k--;
                else j++;
            }
        }
        
        return ans;
    }
};
