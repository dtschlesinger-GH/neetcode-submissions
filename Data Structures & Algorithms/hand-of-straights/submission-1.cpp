class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //sorting makes this trivial, right?
        // what is the greedy approach though????
        if (hand.size() % groupSize != 0) 
        {
            return false;
        }
        if (groupSize <= 1) 
        {
            return true;
        }
        int totalGroups = (int)hand.size() / groupSize;
        vector<list<int>> groups(totalGroups, list<int>());

        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); i++) 
        {
            for (int j = 0; j < groups.size(); j++) 
            {
                if (groups[j].empty()) 
                {
                    groups[j].push_back(hand[i]);
                    if (groups[j].size() == groupSize) 
                    {
                        totalGroups--;
                    }
                    break;
                }
                if (groups[j].size() >= groupSize) 
                {
                    continue;
                }
                if (groups[j].front() - 1 == hand[i]) 
                {
                    groups[j].push_front(hand[i]);
                    if (groups[j].size() == groupSize) 
                    {
                        totalGroups--;
                    }
                    break;
                }
                if (groups[j].back() + 1 == hand[i]) 
                {
                    groups[j].push_back(hand[i]);
                    if (groups[j].size() == groupSize) 
                    {
                        totalGroups--;
                    }
                    break;
                }
            }
        }

        return totalGroups == 0;
    }
};
