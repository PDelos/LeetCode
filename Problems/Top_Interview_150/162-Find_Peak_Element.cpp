class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int l = 0, r = nums.size()-1;
        int m;
        while(l<r){
            m = l+(r-l)/2;
            if(m+1 < nums.size() and nums[m] > nums[m+1]) r= m;
            else l = m+1;
        }

        return l;
    }
};
