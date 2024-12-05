class Solution {
public:
    bool isValid(string s) {
        stack<char>check;
        unordered_map<char, char> brackets = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for(char ch : s){
            if(brackets.find(ch) != brackets.end()){
                check.push(ch);
            }
            else{
                if(check.empty()) return false;
                char bracket = check.top();
                if(brackets.find(bracket) == brackets.end() || brackets[bracket] != ch)
                    return false; 
                check.pop();
            }
        }

        return check.empty();
    }
};
