class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex, rightIndex;
        

        // find left index
        int l = 0, r = nums.size()-1, m;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m] >= target) r = m-1;
            else l = m+1;
        }
        leftIndex = l;

        //find right index
        l = 0, r = nums.size()-1;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m] <= target) l = m+1;
            else r = m-1;
        }
        rightIndex = r;


        if(leftIndex > rightIndex) return {-1, -1};
        return {leftIndex, rightIndex};
    }
};
