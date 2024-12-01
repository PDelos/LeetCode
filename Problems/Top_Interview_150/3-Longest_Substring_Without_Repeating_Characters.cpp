class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, maxLen = 0;
        unordered_set<char>hashTable;

        for(int right = 0; right < n; right++){
            char newChar = s[right];
            cout << newChar << endl;
            while(hashTable.find(newChar) != hashTable.end()){
                hashTable.erase(s[left]);
                ++left;
            }
            maxLen = max(maxLen, right-left+1);
            hashTable.insert(newChar);
        }

        return maxLen;
    }
};
