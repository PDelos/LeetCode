#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Handle empty input

        string ans = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            char match = strs[0][i];
            for (const string& s : strs) {
                // Check if the character at the current position matches
                // or if the index is out of bounds for any string
                if (i >= s.size() || s[i] != match) {
                    return ans;
                }
            }
            ans += match; // Append character to the result
        }

        return ans;
    }
};
