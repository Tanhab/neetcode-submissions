class Solution {
   public:
    using node = pair<double, vector<int> >;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const node& a, const node& b) {return a.first > b.first;};
        priority_queue<node, vector<node>, decltype(cmp)> pq;
        for(auto x : points){
            pq.push({sqrt(x[0]*x[0]+x[1]*x[1]), x});
        }
       vector<vector<int>> ans;
       while(k--){
        auto x  = pq.top();
        pq.pop();
        ans.push_back(x.second);
       } 
       return ans;

    }
};
