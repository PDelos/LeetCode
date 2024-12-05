class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> mergedResult;

        sort(intervals.begin(), intervals.end());
        vector<int>seg = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            
            // pushback when the seg[1] < int[0]
            if(seg[1] < intervals[i][0]){
                mergedResult.push_back(seg);
                seg = intervals[i];
            }

            seg[1] = max(seg[1], intervals[i][1]);
        }
        mergedResult.push_back(seg);
        return mergedResult;
    }
};
