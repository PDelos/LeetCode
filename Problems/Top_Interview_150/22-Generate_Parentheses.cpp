class Solution {
private:
    vector<string>result;

    void genPar(string &s, int open, int close, int &n){
        if(s.size() == 2*n){
            result.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            genPar(s, open+1, close, n);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            genPar(s, open, close+1, n);
            s.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        genPar(s, 0, 0, n);
        return result;
    }
};
