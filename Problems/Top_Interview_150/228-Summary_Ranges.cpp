class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>result;
        if(n == 0)return result;
        
        int start = nums[0];
        for(int i=1; i < n; i++){
            int end = nums[i-1];
            if(end+1 != nums[i]){
                
                if (end != start) {
                    result.push_back(to_string(start) + "->" + to_string(end));
                } else {
                    result.push_back(to_string(end));
                }
                start = nums[i];
            }
        }
        if (start != nums[n-1]) {
            result.push_back(to_string(start) + "->" + to_string(nums[n-1]));
        } else {
            result.push_back(to_string(nums[n-1]));
        }
        return result;
    }
};
