class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>check(2*1e4+1, 0);
        int count = 0;
        for(int& i:nums){
            if(check[i+1e4] > 0){
                i = 1e4+1;
                continue;
            }
            check[i+1e4] += 1;
            count += 1;
        }

        sort(nums.begin(), nums.end());
        return count;
    }
};
