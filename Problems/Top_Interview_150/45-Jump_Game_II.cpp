class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0; // The farthest index we can reach
        int jumps = 0;
        int curMax = 0;

        for (int i = 0; i < nums.size()-1; ++i) {
            // Update the farthest index we can reach
            maxReach = max(maxReach, i + nums[i]);

            if(curMax == i){
                jumps+=1;
                curMax = maxReach;
            }
        }
        
        return jumps;
    }
};
