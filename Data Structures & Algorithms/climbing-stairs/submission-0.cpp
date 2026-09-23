class Solution {
public:
    int RecursiveBacktrack(int remainder, unordered_map<int, int>& memo) 
    {
        if (remainder < 0) 
        {
            return 0;
        }

        if (remainder == 0) 
        {
            return 1;
        }
        
        if (memo.contains(remainder)) 
        {
            return memo[remainder];
        }

        int totalSteps = 0;
        totalSteps = RecursiveBacktrack(remainder - 1, memo) + RecursiveBacktrack(remainder - 2, memo);

        memo[remainder] = totalSteps;
        return totalSteps;
    }

    int climbStairs(int n) {
        // trivial backtrack, but can we make it faster?
            // at each step, choose 1 or 2.  When we hit the target, increment our counter.  return counter
        // we know how many ways we can make 1 and 2, so if we hit those, we don't need to calculate further
        // we also know how many ways we can make a combination of 1 and 2, its con(1) + con(2)
        // unfortunately, the total number of ways to make x doesn not equal con(x-1) + con(remainder)
            // see 5 != con(3) + con(2) nor does con(4) + con(1)

        unordered_map<int, int> memo;
        memo[1] = 1;
        memo[2] = 2;

        return RecursiveBacktrack(n, memo);
    }
};
