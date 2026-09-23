class Solution {
public:
    void Merge(int left, int right, int mid, vector<int>& nums) 
    {
        vector<int> tempVec;
        int leftIndex = left;
        int rightIndex = mid + 1;
        //cout << "indicies for L/M/R are: " << left << "/" << mid << "/" << right << endl; 
        while (leftIndex <= mid && rightIndex <= right) 
        {
            if(nums[leftIndex] <= nums[rightIndex]) 
            {
                //cout << "left index " << nums[leftIndex] << " is less than " << nums[rightIndex] << endl;
                tempVec.push_back(nums[leftIndex]);
                leftIndex++;
            }
            else 
            {
                //cout << "right index " << nums[rightIndex] << " is less than " << nums[leftIndex] << endl;
                tempVec.push_back(nums[rightIndex]);
                rightIndex++;
            }
        }

        while (leftIndex <= mid) 
        {
            tempVec.push_back(nums[leftIndex]);
            leftIndex++;
        }
        while (rightIndex <= right) 
        {
            tempVec.push_back(nums[rightIndex]);
            rightIndex++;
        }
        for (int i = left; i <= right; i++) 
        {
            //cout << "writing " << tempVec[i - left] << " at index " << i << endl;
            nums[i] = tempVec[i - left];
        }
    }

    void RecursiveBacktrack(int left, int right, vector<int>& nums) 
    {
        if (left >= right) 
        {
            return;
        }

        int mid = left + (right - left) / 2;

        RecursiveBacktrack(left, mid, nums);
        RecursiveBacktrack(mid + 1, right, nums);
        Merge(left, right, mid, nums);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        RecursiveBacktrack(0, nums.size() - 1, nums);
        return nums;    
    }
};