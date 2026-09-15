class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int cnt = 0, n = triplets.size();
        bool xx = false, yy = false, zz = false;
        int x, y, z;
        for (int i = 0; i < n; i++) {
            x = triplets[i][0], y = triplets[i][1], z = triplets[i][2];
            if(x == target[0] && y<=target[1] && z <= target[2])
                xx = true;
            if(y == target[1] && x<=target[0] && z <= target[2])
                yy = true;
            if(z == target[2] && y<=target[1] && x <= target[0])
                zz = true; 
        }

        return xx & yy & zz;
    }
};
