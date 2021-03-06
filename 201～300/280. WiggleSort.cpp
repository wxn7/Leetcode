/*

Given an unsorted array nums, reorder it in-place such that 
nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], 
one possible answer is [1, 6, 2, 5, 3, 4].

*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        while (i < n) {
            //i increase by 2 in each loop
            if (i + 1 < n && nums[i] > nums[i + 1])
                swap(nums[i], nums[i + 1]);
            i++;
            if (i + 1 < n && nums[i] < nums[i + 1])
                swap(nums[i], nums[i + 1]);
            i++;
        }
    }
};


////////////
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool flag = true;
        for (int i = 1; i < nums.size(); i++) {
            if (flag) {
                if (nums[i] < nums[i - 1])
                    swap(nums[i], nums[i - 1]);
                flag = false;
            }
            else {
                if (nums[i] > nums[i - 1])
                    swap(nums[i], nums[i - 1]);
                flag = true;
            }
        }
    }
};