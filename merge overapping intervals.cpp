class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        
        if(intervals.size() == 0)
        {
            return mergedIntervals;
        }
        
        sort(intervals.begin(), intervals.end());
        vector<int> interval = intervals[0];
        
        for(auto it : intervals)
        {
            if(it[0] <= interval[1])
            {
                interval[1] = max(interval[1], it[1]);
            }
            else
            {
                mergedIntervals.push_back(interval);
                interval = it;
            }
        }
        
        mergedIntervals.push_back(interval);
        return mergedIntervals;
    }
};
