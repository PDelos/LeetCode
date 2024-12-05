class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>calculator;
        for(string token : tokens){
            if(token == "+"){
                // Suation logic
                int n1 = calculator.top(); calculator.pop();
                int n2 = calculator.top(); calculator.pop();
                calculator.push(n1+n2);
            } else if (token == "-"){
                // Substraction logic
                int n1 = calculator.top(); calculator.pop();
                int n2 = calculator.top(); calculator.pop();
                calculator.push(n2-n1);
            } else if (token == "*"){
                // Multiplication logic
                int n1 = calculator.top(); calculator.pop();
                int n2 = calculator.top(); calculator.pop();
                calculator.push(n1*n2);
            } else if (token == "/"){
                // Division logic
                int n1 = calculator.top(); calculator.pop();
                int n2 = calculator.top(); calculator.pop();
                calculator.push(n2/n1);
            } else {
                // If not logic thn a number
                int num = stoi(token);
                calculator.push(num);
            }
        }

        return calculator.top();
    }
};
