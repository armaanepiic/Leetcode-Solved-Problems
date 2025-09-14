class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size() + 1;
        vector<int> arr(size, 0);
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]] = 1;
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] == 0)
                return i;
        }
        return 0;
    }
};