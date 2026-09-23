class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binairy search to find X (or the closest element to it), then start expanding the window from there.
        // alternatively, we can just use a minheap, and keep pairs of distance, num on it
        
        int leftBound = 0;
        int rightBound = arr.size() - 1;
        while (leftBound < rightBound) 
        {
            int mid = leftBound + (rightBound - leftBound) / 2;
            if (arr[mid] < x) 
            {
                leftBound = mid + 1;
            }
            else 
            {
                rightBound = mid;
            }
        }

        leftBound -= 1;
        rightBound = leftBound + 1;
        while (rightBound - leftBound - 1 < k) 
        {
            if (leftBound < 0) 
            {
                rightBound++;
                continue;
            }
            if (rightBound >= arr.size()) 
            {
                leftBound--;
                continue;
            }
            if (abs(arr[leftBound] - x) <= abs(arr[rightBound] - x)) 
            {
                leftBound --;
            }
            else 
            {
                rightBound++;
            }
        }

        return vector<int>(arr.begin() + leftBound + 1, arr.begin() + rightBound);
    }
};