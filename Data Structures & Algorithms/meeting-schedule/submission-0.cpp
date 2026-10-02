/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) { return a.start < b.start; });
             for(auto x : intervals)
                cout << x.start << "-" << x.end << endl;
        int i = 0, prevH = -1;
        while(i < intervals.size()){
            if(intervals[i].start < prevH)
                return false;
            
            prevH = intervals[i].end;
            i++;
        }
        return true;
    }
};
