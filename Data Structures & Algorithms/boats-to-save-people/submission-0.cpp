class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int leftIndex = 0;
        int rightIndex = people.size() - 1;
        int boatCount = 0;

        while (leftIndex <= rightIndex) 
        {
            if (people[leftIndex] + people[rightIndex] <= limit) 
            {
                leftIndex++;
                rightIndex--;
                boatCount++;
            }
            else 
            {
                rightIndex--;
                boatCount++;
            }
        }
        return boatCount;
    }
};