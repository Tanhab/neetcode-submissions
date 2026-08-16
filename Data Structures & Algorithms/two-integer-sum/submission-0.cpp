class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mp;
       vector<int> ans;
       for(int i = 0 ; i < ssize(nums); i++){
            if(!mp.contains(nums[i]))   mp[nums[i]] = i;
       } 
       for(int i = 1 ; i < ssize(nums); i++){
        
            if(mp.contains(target - nums[i]) && i != mp[target - nums[i]]){
                ans.push_back(min(i, mp[target - nums[i]]));
                ans.push_back(max(i, mp[target - nums[i]]));
                break;
            }
       }
       return ans;
    }
};
