class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& group : map) {
            ans.push_back(group.second);
        }
        return ans;
    }
};
