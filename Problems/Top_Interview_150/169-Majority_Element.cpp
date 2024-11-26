class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majElement = nums[0];

        for (int x : nums){
            if (count == 0){
                majElement = x;
            }
            count += x == majElement ? 1 : -1; 
        }

        return majElement;
    }
};
