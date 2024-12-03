class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hash;   // Maps pattern characters to words
        unordered_set<string> seen;        // Tracks words already mapped

        istringstream stream(s);
        int i = 0;
        string word;

        while (stream >> word) {
            
            char c = pattern[i];
            if (hash.find(c) != hash.end()) {
                if (hash[c] != word) 
                    return false;
            } else {
                if (seen.count(word)) 
                    return false;
                hash[c] = word;
                seen.insert(word);
            }
            ++i;
        }

        return i == pattern.size();
    }
};
