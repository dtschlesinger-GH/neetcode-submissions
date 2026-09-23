class Solution {
public:
    int maxArea(vector<int>& heights) {
        // from math, this is height * dist.  
        // If we start at the outsides, we know that any heights lower than out min height don't matter, so we are only looking for larger ones
        // We should move the smaller of the two indicies inward, if we do find one.  If they are tied, move the one closer.  
        // If both the same distance, move the the one with larger height.  If both the same size and dist, do left
        // when Left >= right, we have exhausted all possibilities

        int maxArea = 0;
        int leftIndex = 0;
        int rightIndex = heights.size() - 1;
        int smallestHeight = 0;

        while (leftIndex < rightIndex) 
        {
            smallestHeight = min(heights[leftIndex], heights[rightIndex]);
            maxArea = max(maxArea, (rightIndex - leftIndex) * smallestHeight);

            if (heights[leftIndex] < heights[rightIndex]) 
            {
                //left is lower
                int numToBeat = heights[leftIndex];
                while (numToBeat >= heights[leftIndex]) 
                {
                    leftIndex++;
                }
                
            }
            else if (heights [leftIndex] > heights[rightIndex]) 
            {
                // right is lower
                int numToBeat = heights[rightIndex];
                while (numToBeat >= heights[rightIndex]) 
                {
                    rightIndex--;
                }
            }
            else 
            {
                // same height
                int subLeftIndex = leftIndex + 1;
                int subRightIndex = rightIndex -1 ;
                bool foundNewHeight = false;
                for (; subLeftIndex < subRightIndex; subLeftIndex++) 
                {
                    if (heights[subLeftIndex] > heights[leftIndex]) 
                    {
                        foundNewHeight = true;
                        break;
                    }
                    if (heights[subRightIndex] > heights[rightIndex]) 
                    {
                        foundNewHeight = true;
                        break;
                    }
                    subRightIndex--;
                }
                if (!foundNewHeight) 
                {
                    leftIndex = rightIndex;
                }
                else 
                {
                    int leftDist = abs(subLeftIndex - leftIndex);
                    int rightDist = abs(subRightIndex - rightIndex);
                    if (leftDist <= rightDist) 
                    {
                        leftIndex = subLeftIndex;
                    }
                    else
                    {
                        rightIndex = subRightIndex;
                    }
                }
            }
        }
        return maxArea;
    }
};
