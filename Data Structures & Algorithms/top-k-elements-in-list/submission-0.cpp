class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> numOccurances(2001, 0);
        for (int numsIdx = 0; numsIdx < nums.size(); numsIdx++) 
        {
            numOccurances[nums[numsIdx] + 1000]++;
        }
        vector<pair<int, int>> numAndFreq(k, {0,0});
        for (int occuranceIdx = 0; occuranceIdx < numOccurances.size(); occuranceIdx++) 
        {
            for (int traversalIdx = 0; traversalIdx < k; traversalIdx++) {
                if (numOccurances[occuranceIdx] >= numAndFreq[traversalIdx].second) {
                    numAndFreq.insert(numAndFreq.begin() + traversalIdx, {occuranceIdx - 1000, numOccurances[occuranceIdx]});
                    numAndFreq.pop_back();
                    break;
                }
            }
        }
        vector<int> toReturn;
        for (const auto& element : numAndFreq) {
            toReturn.push_back(element.first);
        }

        return toReturn;
    }
};
