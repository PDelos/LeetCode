class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Declare all variables that will be used (Total: O(1) excluding answer)
        int n =  nums.size();
        vector<int> answer(n, 1);

        for(int i = 1; i < n; i++){
            answer[i] = answer[i-1] * nums[i-1];
        }

        int res = 1;
        for(int i = n-2; i >= 0; i--){
            res *= nums[i+1];
            answer[i] *= res;
        }

        return answer;
    }
};
