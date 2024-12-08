class Solution {
private:
    vector<vector<int>> solution;

    void backtracking(vector<int> &curr, int k, int n, int pos){
        if(curr.size() == k){
            solution.push_back(curr);
            return;
        }

        for(int i = pos; i <= n; i++){
            curr.push_back(i);
            backtracking(curr, k, n, i+1);
            curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr = {};
        backtracking(curr, k, n, 1);
        return solution;

    }
};
