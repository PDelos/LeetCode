class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // gas = [1,2,3,4,5]
        // cost = [3,4,5,1,2]
        // result = [-2, -2, -2, 3, 3]

        // gas = [2, 3, 4]
        // cost = [3, 4, 3]
        // result = [-1, 1,-1]

        // if sum is negative --> -1
        // cannot start at a negative position


        // Decalre 
        int n = gas.size();
        vector<int>v(n);
        int sum = 0, startIndex = 0, i;

        for(i = 0; i < n; i ++){
            v[i] = gas[i] - cost[i];
            sum += v[i];
        }

        if (sum < 0) return -1;

        int curGas = 0;
        for(i = 0; i < n; i++){
            curGas += v[i];
            if(curGas < 0){
                startIndex = i+1;
                curGas = 0;
            }
        }
        return startIndex;
    }
};
