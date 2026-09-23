class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Obvious/brute force solution is sort the array from least to greatest, then go down the right side until you hit 0s
        // but that turns everything into O(Nlog(n))
        int rightWindow = 0;
        int runningTotal = 0;
        int subTotal = 0;

        subTotal = nums[0];
        for (; rightWindow < nums.size(); rightWindow++) 
        {
            runningTotal += nums[rightWindow];
            subTotal = max(subTotal, runningTotal);
            if (nums[rightWindow] < 0) {
                    if (runningTotal <= 0 && rightWindow != nums.size() - 1)  
                    {
                        cout << "dumping total at index: " << rightWindow << endl;
                        runningTotal = 0;
                        continue;
                    }
            }
        }
        return subTotal;
    }
};
