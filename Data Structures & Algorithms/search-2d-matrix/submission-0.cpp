class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int t = n * m;
        int l = 0, r = t -1;

        while( l <= r){
            int mid = l + ( r-l) / 2;
            int mr = mid / m, mc = mid % m;

            if(matrix[mr][mc] == target) return true;
            else if(matrix[mr][mc] < target)
                l = mid + 1;
            else r = mid - 1;
        }

        return false;
        
    }
};
