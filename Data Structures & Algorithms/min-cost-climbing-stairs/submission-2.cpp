class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dist(n+5,0);
        for(int i = 2; i<= n; i++){
            dist[i] = min(dist[i-1] + cost[i-1], dist[i-2] + cost[i-2]);
        }
        return dist[n];
    }
};
