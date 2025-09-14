class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool flag;
        for (int i = 0; i <= nums.size(); i++) {
            flag = false;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == i) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return i;
            }
        }
        return 0;
    }
};