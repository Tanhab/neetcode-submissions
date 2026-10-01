class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        int nl = newInterval[0], nh = newInterval[1];
        vector<vector<int>> ans;
        if (n == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        int l = nl, h = nh;

        // ebfore  nh < l
        // after nl > h
        if (nh < intervals[0][0]) {
            ans.push_back(newInterval);
            ans.insert(ans.end(), intervals.begin(), intervals.end());
            return ans;
        }
        int cl, ch;
        while (i < n) {
            cl = intervals[i][0], ch = intervals[i][1];
            // cl...ch..nl..nh
            if (nl > ch) {
                ans.push_back(intervals[i]);
                i++;
                continue;
            }
            // l/nl..cl..h/nh..ch
            if (h <= ch && h == nh) {
                if (cl > h) {
                    ans.push_back({min(l,cl), h});
                    ans.push_back(intervals[i]);
                } else
                    ans.push_back({min(l,cl), intervals[i][1]});
                h = intervals[i][1];
                i++;
                continue;
            }

            // l/nl..cl..h..ch
            if (cl > h) {
                ans.push_back(intervals[i]);
                i++;
                continue;
            }
            //
            l = min(cl,l);
            h = max(h, ch);
            i++;
        }
        if (h > ch) ans.push_back({l, h});

        return ans;
    }
};
