class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> numIndexHash;

        for (int index = 0; index < nums.size(); index++) 
        {
            auto itr = numIndexHash.find(nums[index]);
            // if we found an identical number
            if (itr != numIndexHash.end()) 
            {
                // check if the indicies hashed here meet our request
                for (const int& element : numIndexHash[nums[index]]) 
                {
                    if (abs(element - index) <= k) 
                    {
                        return true;
                    }
                }
            }
            numIndexHash[nums[index]].push_back(index);
        }
        return false;
    }
};