class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pS = 0;
        int pT = 0;

        while(pS < s.size() and pT < t.size()){
            if(s[pS] == t[pT]) pS++;
            pT++;
        }
        return pS == s.size();
    }
};
