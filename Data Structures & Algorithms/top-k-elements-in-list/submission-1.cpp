class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFreq;
        vector<int> toReturn;
        vector<vector<int>> frequencyByIndex(nums.size(), vector<int>());

        for (int numsIdx = 0; numsIdx < nums.size(); numsIdx++) {
            numFreq[nums[numsIdx] + 1000] += 1;
        }

        for (const auto& numFreqPair : numFreq) 
        {
            frequencyByIndex[numFreqPair.second - 1].push_back(numFreqPair.first - 1000);
        }

        for (int highestIdx = frequencyByIndex.size() - 1; highestIdx >= 0; highestIdx--) 
        {
            if (!frequencyByIndex[highestIdx].empty()) 
            {
                for (const int& element : frequencyByIndex[highestIdx]) 
                {
                    toReturn.push_back(element);
                }
            }
            if (toReturn.size() == k) {
                return toReturn;
            }

        }
        return toReturn;
    }
};
