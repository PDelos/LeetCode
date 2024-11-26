class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(int& i : nums){
            if(i == val) {
                i = 51;
                k-=1;
            }
        }

        sort(nums.begin(), nums.end());
        return k;
    }
};
