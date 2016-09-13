class NumArray {
    vector<int> sums; //store sum of index[0, i]
public:
    NumArray(vector<int> &nums) {
        if (nums.size() != 0) {
            sums.push_back(nums[0]);
            for (int i = 1; i < nums.size(); ++i)
                sums.push_back(sums[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return (sums[j] - sums[i - 1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);