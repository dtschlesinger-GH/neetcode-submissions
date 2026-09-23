class Solution {
public:
    unordered_map<int, int> solved;

    int RecursiveBacktrack(int currentIndex, const vector<int>& nums) 
    {
        if (currentIndex == nums.size() - 1) 
        {
            return 0;
        }
        if (currentIndex >= nums.size()) 
        {
            return -1;
        }
        if (solved.contains(currentIndex)) 
        {
            return solved[currentIndex];
        }
        if (nums[currentIndex] == 0) 
        {
            return 100000;    
        }

        int minSteps = 1000000;
        int end = min((int)nums.size(), currentIndex + nums[currentIndex] + 1);
        for (int jumpStrength = currentIndex + 1; jumpStrength < end; jumpStrength++) 
        {
            minSteps = min(minSteps, 1 + RecursiveBacktrack(currentIndex + jumpStrength, nums));
        }

        solved[currentIndex] = minSteps;
        return minSteps;
    }

    int jump(vector<int>& nums) {
        // backtracking and DP are trivial, can just write to a min
        // I should write them anyway to get practice
        //return RecursiveBacktrack(0, nums);

        int leftIndex = 0;
        int rightIndex = 0;
        int minJumps = 0;

        while (rightIndex < nums.size() - 1) 
        {
            int farthest = 0;
            for (int currentIndex = leftIndex; currentIndex <= rightIndex; currentIndex++) 
            {
                farthest = max(farthest, currentIndex + nums[currentIndex]);
            }
            leftIndex = rightIndex + 1;
            rightIndex = farthest;
            minJumps++;
        }
        return minJumps;
    }
};
