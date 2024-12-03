class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        for(uint8_t i = 0; i <=32; i++){
            bool bit = n & 1;
            result += bit;
            n = n >> 1;
        }
        return result;
    }
};
