class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // The farthest index we can reach
        
        for (int i = 0; i < nums.size(); ++i) {
            // If we are at a position that is not reachable, return false
            if (i > maxReach) return false;
            
            // Update the farthest index we can reach
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can reach or surpass the last index, return true
            if (maxReach >= nums.size() - 1) return true;
        }
        
        return false;
    }
};
