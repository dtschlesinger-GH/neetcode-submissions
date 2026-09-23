class Solution {
public:
    int RecursiveBacktrack(int value, unordered_map<int, long>& memo) 
    {
        if (memo.contains(value)) 
        {
            return memo[value];
        }

        if (value < 0) 
        {
            return 0;
        }

        long totalVal = RecursiveBacktrack(value - 1, memo) + RecursiveBacktrack(value - 2, memo) + RecursiveBacktrack(value - 3, memo);
        memo[value] = totalVal;
        return totalVal;
    }

    int tribonacci(int n) {
        unordered_map<int, long> tribToVal;
        tribToVal[0] = 0;
        tribToVal[1] = 1;
        tribToVal[2] = 1;

        return RecursiveBacktrack(n, tribToVal);
    }
};