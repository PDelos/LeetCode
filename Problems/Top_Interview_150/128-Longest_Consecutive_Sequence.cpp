class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hash(nums.begin(), nums.end());

        int longest = 0;
        int len = 0;

        for(int num : nums){
            if(hash.find(num-1) == hash.end()){
                len = 1;
                while(hash.find(num+len) != hash.end()){
                    ++len;
                }
                longest = max(len, longest);
            }
        }
        return longest; 
    }
};
