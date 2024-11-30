class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); 
        int pref[n], suff[n]; 
        int i;
        int totalCandy = 0;
        
        pref[0] = 1; 
        for(i = 1; i<n; i++){
            if(ratings[i] > ratings[i-1]) pref[i] = pref[i-1]+1;
            else pref[i] = 1;
        }

        suff[n-1] = 1; 
        for(i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]) suff[i] = suff[i+1]+1;
            else suff[i] = 1;
        }

        for(i=0; i<n; i++) totalCandy += max(pref[i], suff[i]);

        return totalCandy;
    }
};
