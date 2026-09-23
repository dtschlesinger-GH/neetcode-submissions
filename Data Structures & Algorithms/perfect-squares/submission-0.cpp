class Solution {
public:
    int RecursiveBacktrack(int remainder, unordered_map<int, int>& sumTotals) 
    {
        if (sumTotals.contains(remainder)) 
        {
            return sumTotals[remainder];
        }

        if (remainder <= 0) 
        {
            return 0;
        }

        int totalSquares = remainder;
        for (int i = 1; i * i <= remainder; i++) 
        {
            totalSquares = min(totalSquares, 1 + RecursiveBacktrack(remainder - i * i, sumTotals)); 
        }
        return sumTotals[remainder] = totalSquares;
    }

    int numSquares(int n) {
        unordered_map<int, int> sumToNumTotal;
        sumToNumTotal[1] = 1;
        sumToNumTotal[2] = 2;
        sumToNumTotal[3] = 3;
        sumToNumTotal[4] = 1;

        return RecursiveBacktrack(n, sumToNumTotal);
    }
};