class MinStack {
private:
    stack<vector<int>>minSt;
    int minVal=INT_MAX;

public:
    MinStack() {
    }
    
    void push(int val) {
        if(minSt.empty() || minVal > val){
            minVal = val;
        }
        minSt.push({val, minVal});
    }
    
    void pop() {
        minSt.pop();
        minVal = minSt.empty() ? INT_MAX:minSt.top()[1];
    }
    
    int top() {
        return minSt.top()[0];
    }
    
    int getMin() {
        return minSt.top()[1];
    }
};
