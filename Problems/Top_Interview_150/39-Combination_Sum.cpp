class Solution {
private:
    vector<vector<int>> result;
    vector<int> numbers;
    int targetSum;

    void findCombinations(vector<int>& current, int currentSum, int pos) {
        if (currentSum == targetSum) {
            result.push_back(current);
            return;
        }

        for (int i = pos; i < numbers.size(); i++) {
            int num = numbers[i];
            if (currentSum + num > targetSum) continue;
            current.push_back(num);
            findCombinations(current, currentSum + num, i);
            current.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        numbers = candidates;
        targetSum = target;
        vector<int> currentCombination = {};
        findCombinations(currentCombination, 0, 0);
        return result;
    }
};
