class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int runningTotal = 0;
        float avg = 0.0;
        int rightWindow = 0;
        int totalSubarrays = 0;
        for (; rightWindow < arr.size(); rightWindow++) 
        {
            runningTotal += arr[rightWindow];
            if (rightWindow >= k - 1) 
            {
                avg = ((float)runningTotal / (float)k);
                if (avg >= (float)threshold) 
                {
                    totalSubarrays++;
                }
                runningTotal -= arr[rightWindow - (k - 1)];
            }
        }
        return totalSubarrays;
    }
};