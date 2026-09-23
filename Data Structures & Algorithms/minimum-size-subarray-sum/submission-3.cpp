class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int leftWindow = 0;
        int rightWindow = 0;
        int minLength = 999999;
        int runningTotal = 0;

        for (; rightWindow < nums.size(); rightWindow++) 
        {
            runningTotal += nums[rightWindow];
                while (runningTotal >= target) 
                {
                    minLength = min(minLength, (rightWindow - leftWindow + 1));
                    runningTotal -= nums[leftWindow];
                    leftWindow++;
                }
        }
        return minLength > 100000 ? 0 : minLength;
    }
};