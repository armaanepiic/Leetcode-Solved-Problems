class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k >= nums.size())
            k = k % nums.size();
        vector<int> store(k);
        for (int i = 0; i < k; i++)
            store[k - 1 - i] = nums[nums.size() - i - 1];

        int l = nums.size() - k - 1;

        while(l >= 0){
            nums[l+k] = nums[l];
            l--;
        }
        for (int i = 0; i < k; i++)
            nums[i] = store[i];
    }
};