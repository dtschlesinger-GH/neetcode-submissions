public class Solution {
    public int[] CountBits(int n) {
        int[] numBits = new int[n+1];
        for (int i = 0; i <= n; i++) 
        {
            int currentNum = i;
            while (currentNum != 0) 
            {
                currentNum &= currentNum - 1;
                numBits[i] += 1;
            }
        }
        return numBits;
    }
}
