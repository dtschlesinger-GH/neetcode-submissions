class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> numBits(n + 1, 0);
        for (int i = 1; i <= n; i++) 
        {
            int num = i;
            while (num != 0) {
                numBits[i]++;
                num &= (num - 1);
            }
        }
        return numBits;
    }
};
