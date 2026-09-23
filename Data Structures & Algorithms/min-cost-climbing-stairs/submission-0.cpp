class Solution {
public:
    int RecursiveBacktrack(unordered_map<int, int>& stairMinCost, const vector<int>& cost, int currentStep) 
    {
        if (currentStep > cost.size()) 
        {
            //we never want to step out of bounds, so don't let us record that
            return 99999;
        }
        if (currentStep == cost.size()) 
        {
            // I got here from stair 1 or stair 2, it doesn't cost me anything to step
            return 0;
        }
        if (stairMinCost.contains(currentStep)) 
        {
            return stairMinCost[currentStep];
        }

        // Total cost to traverse stair(x) is the cost of X + the min cost of stair (x + 1) and (x + 2)
        int totalCost;
        totalCost = cost[currentStep] + min(RecursiveBacktrack(stairMinCost, cost, currentStep + 1), RecursiveBacktrack(stairMinCost, cost, currentStep + 2));

        stairMinCost[currentStep] = totalCost;
        return totalCost;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> stairMinCost;
        int index = cost.size() - 1;
        if (index == 0) 
        {
            return cost[index];
        }
        stairMinCost[index] = cost[index];
        stairMinCost[index - 1] = cost[index - 1];

        return min(RecursiveBacktrack(stairMinCost, cost, 0), RecursiveBacktrack(stairMinCost, cost, 1));
    }
};
