class Solution {
public:
    unordered_map<int, bool> indexCanFinish;
    bool RecursiveBacktrack(int currentIndex, vector<int>& jumpIndex) 
    {
        if (currentIndex == jumpIndex.size() - 1) 
        {
            //cout << "reached index " << currentIndex << " successfully" << endl;\
            indexCanFinish[currentIndex] = true;
            return true;
        }
        if (currentIndex >= jumpIndex.size()) 
        {
            return false;
        }
        if (indexCanFinish.contains(currentIndex)) 
        {
            return indexCanFinish[currentIndex];
        }
        for (int jumpStrength = 1; jumpStrength <= jumpIndex[currentIndex]; jumpStrength++) 
        {
            //cout << "Jumping from index " << currentIndex << " with a strength of " << jumpStrength << endl;
            if (RecursiveBacktrack(currentIndex + jumpStrength, jumpIndex))
            {
                return true;
            }            
        }
        indexCanFinish[currentIndex] = false;
        return false;
    }

    bool canJump(vector<int>& nums) 
    {
        return RecursiveBacktrack(0, nums);
    }
};
