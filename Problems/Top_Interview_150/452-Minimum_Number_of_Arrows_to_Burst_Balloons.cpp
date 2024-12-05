class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(!points.size()) return 0;


        sort(points.begin(), points.end());
        vector<int>seg = points[0];
        int count = 1;
        for(int i = 1; i < points.size(); i++){
            
            // pushback when the seg[1] < int[0]
            if(seg[1] < points[i][0]){
                ++count;
                seg = points[i];
            }
            else{
                seg[1] = min(seg[1], points[i][1]);
            }
        }
        return count;
    }
};
