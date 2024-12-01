class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1; // Fix: Use size() - 1 for the last index

        while (i < j) { // Fix: Ensure `i < j` to avoid redundant checks
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1}; // Return 1-based indices
            } else if (sum < target) {
                i++; // Move the left pointer right
            } else {
                j--; // Move the right pointer left
            }
        }

        return {}; // Return an empty vector if no solution is found
    }
};
