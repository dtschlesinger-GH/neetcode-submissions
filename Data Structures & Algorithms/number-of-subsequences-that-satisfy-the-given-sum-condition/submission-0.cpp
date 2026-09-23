class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, mod = 1000000007;
        int r = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            while (i <= r && nums[i] + nums[r] > target) {
                r--;
            }
            if (i <= r) {
                res = (res + power(2, r - i, mod)) % mod;
            }
        }
        return res;
    }

private:
    long long power(int base, int exp, int mod) {
        long long result = 1, b = base;
        while (exp > 0) {
            if (exp & 1) result = (result * b) % mod;
            b = (b * b) % mod;
            exp >>= 1;
        }
        return result;
    }
};