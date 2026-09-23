class Solution {
public:
    bool RecursiveBacktrack(int currentIndex, vector<int>& jumpIndex) 
    {
        if (currentIndex == jumpIndex.size() - 1) 
        {
            //cout << "reached index " << currentIndex << " successfully" << endl;
            return true;
        }
        if (currentIndex >= jumpIndex.size()) 
        {
            return false;
        }
        for (int jumpStrength = 1; jumpStrength <= jumpIndex[currentIndex]; jumpStrength++) 
        {
            //cout << "Jumping from index " << currentIndex << " with a strength of " << jumpStrength << endl;
            if (RecursiveBacktrack(currentIndex + jumpStrength, jumpIndex))
            {
                return true;
            }            
        }
        return false;
    }

    bool canJump(vector<int>& nums) 
    {
        return RecursiveBacktrack(0, nums);
    }
};
