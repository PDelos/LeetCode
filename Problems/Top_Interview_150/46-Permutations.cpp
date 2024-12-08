class Solution {
private:
    vector<vector<int>>solution;
    bool vis[7];
    int n;

    void backtracking(vector<int>& nums, vector<int>& curr){
        if(curr.size() == n){
            solution.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            curr.push_back(nums[i]);
            vis[i] = true;
            backtracking(nums, curr);
            curr.pop_back();
            vis[i] = false;
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int>curr = {};
        backtracking(nums, curr);
        return solution;    
    }
};
