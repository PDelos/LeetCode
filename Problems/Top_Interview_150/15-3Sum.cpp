class Solution {

private:
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for(int i = 0; i < nums.size(); i++){
            if (i+1 < nums.size() && nums[i] == nums[i+1]) {
                continue;
            }
            
            int j=0, k = i-1;
            while(j < k){
                if(nums[j] + nums[k] + nums[i] == 0) {
                    ans.push_back({nums[j], nums[k], nums[i]});
                    --k;
                    while(nums[k] == nums[k+1] && j < k) --k;
                }
                else if(nums[j] + nums[k] + nums[i] < 0){
                    ++j;
                }
                else{
                    --k;
                }
            }
        }
        
        
        return ans;
    }
};
