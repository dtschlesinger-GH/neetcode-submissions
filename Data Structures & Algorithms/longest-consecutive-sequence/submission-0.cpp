class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // run through write to hashmap on first pass
        // second pass, find in hashmap, find furthest x-1 back and n+1 forward in hashmap, write to max
        // each one you find, write into second hashmap so we don't repeat anything.
        // once you have finished second pass, return max

        unordered_set<int> numHash;
        unordered_set<int> numsUsed;
        int maxSeq = 0;


        for (const int element : nums) {
            numHash.insert(element);
        }

        for (const int element : nums) {
            if (!numsUsed.contains(element)) {
                numsUsed.insert(element);
                int smallest = element;
                int largest = element;
                while (numHash.contains(smallest)) {
                    numsUsed.insert(smallest);
                    smallest--;
                }
                while (numHash.contains(largest)) {
                    numsUsed.insert(largest);
                    largest++;
                }
                smallest++;
                largest--;
                maxSeq = max(maxSeq, abs(largest - smallest) + 1);
            }
        }
        return maxSeq;
    }
};
