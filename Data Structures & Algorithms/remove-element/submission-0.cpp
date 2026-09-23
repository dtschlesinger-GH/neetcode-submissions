class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        while (index < nums.size()) 
        {
            if (nums[index] == val) 
            {
                cout << "array size is " << nums.size() << ", swapping " << nums[index] << " for " << nums[nums.size() - 1] << endl;
                int temp = nums[nums.size() - 1];
                nums[nums.size() - 1] = nums[index];
                nums[index] = temp;
                cout << "Number at " << index << " is now " << nums[index] << endl;
                nums.pop_back();
            }
            else 
            {
                index++;
            }
        }
        return nums.size();
    }
};