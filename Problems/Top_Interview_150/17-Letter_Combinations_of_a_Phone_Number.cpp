class Solution {
private:
    unordered_map<char, string>letters = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};

    vector<string>solution;
    int n;

    void backtracking(string &s, int pos, string &digits){
        if(pos == n){
            solution.push_back(s);
            return;
        }

        for(char c : letters[digits[pos]]){
            s.push_back(c);
            backtracking(s, pos+1, digits);
            s.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(!n) return vector<string>();
        string s = "";
        backtracking(s, 0, digits);

        return solution;
    }
};
