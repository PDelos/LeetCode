class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> r2i;
        r2i['I'] = 1;
        r2i['V'] = 5;
        r2i['X'] = 10;
        r2i['L'] = 50;
        r2i['C'] = 100;
        r2i['D'] = 500;
        r2i['M'] = 1000;

        int num = 0;
        for(int i = 0; i < s.size()-1; i++){
            if(r2i[s[i]] >= r2i[s[i+1]]) num += r2i[s[i]];
            else  num -= r2i[s[i]];
        }
        return num + r2i[s[s.size()-1]];

    }
};
