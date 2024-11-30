class Solution {
public:
    int trap(vector<int>& height) {
        int maxH = -1, maxI = -1;
        int n = height.size();

        for(int i = 0; i < n; i++){
            if(height[i] > maxH){
                maxH = height[i];
                maxI = i;
            }
        }

        int water = 0, curMax = -1;
        for(int i = 0; i < maxI; i++){
            if(curMax < height[i]) curMax = height[i];
            water += curMax-height[i];
        }
        
        curMax = -1;
        for(int i = n-1; i > maxI; i--){
            if(curMax < height[i]) curMax = height[i];
            water += curMax-height[i];
        }

        return water;
    }
};
