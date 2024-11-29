class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n  = citations.size();
        sort(citations.begin(), citations.end());

        int l = 0, r = n-1, m;
        int ans = 0;
        while(l <= r){
            m = l+(r-l)/2;
            ans=max(ans,min(citations[m], n-m));
            
            if( n-m >= citations[m]) l = m+1;
            else r=m-1;
        }
        return ans;
    }
};
