class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIdx = 0;
        int rightIdx = numbers.size() - 1;
        vector<int> toReturn;

        while (leftIdx < rightIdx) 
        {
            if (numbers[leftIdx] + numbers[rightIdx] > target) 
            {
                rightIdx--;
            }
            else if (numbers[leftIdx] + numbers[rightIdx] < target) 
            {
                leftIdx++;
            }
            else {
                break;
            }
        }
        toReturn.push_back(leftIdx + 1);
        toReturn.push_back(rightIdx + 1);
        return toReturn;
    }
};
