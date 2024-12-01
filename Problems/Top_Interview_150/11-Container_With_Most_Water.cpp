class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        
        int maxWater = -1;
        int curWater;
        while(i < j){
            curWater = min(height[i], height[j])*(j-i);
            if(curWater > maxWater) maxWater = curWater;
            if(height[i] <= height[j]) ++i;
            else --j;
        }

        return maxWater;
    }
};
