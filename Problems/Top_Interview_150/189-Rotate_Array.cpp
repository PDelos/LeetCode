class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();

        // this is equal to reversing the array 3 times
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
