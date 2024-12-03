class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>hash;
        unordered_set<char> used;

        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) != hash.end()) {
                if(hash[s[i]] != t[i]) return false;
            } else {
                if (used.count(t[i])) return false;
                hash[s[i]] = t[i];
                used.insert(t[i]);
            }
        }
        return true;
    }
};
