class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumOfNums = 0;
        int n = nums.size();
        int totalOfFirstN = n * (n+1) / 2;
        for(int i = 0 ; i < nums.size() ; i++)
            sumOfNums += nums[i];
        return totalOfFirstN - sumOfNums;
    }
};