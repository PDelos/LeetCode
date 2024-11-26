class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>check(201, 0);
        int count = 0;
        for(int& i:nums){
            if(check[i+100] > 0){
                i = 101;
                continue;
            }
            check[i+100] += 1;
            count += 1;
        }

        sort(nums.begin(), nums.end());
        return count;
    }
};
