# 189. Rotate Array

**Problem Link:** [LeetCode 189 - Rotate Array](https://leetcode.com/problems/rotate-array/description/)  
**Category:** Array

## Problem Description

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

## Examples

### Example 1
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

### Example 2
```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

## Constraints

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `0 <= k <= 10^5`

## Solution Approach: Store and Shift Method

**Time Complexity:** O(n) - where n is the length of the array  
**Space Complexity:** O(k) - for storing the last k elements

### Algorithm Steps:

1. **Handle Redundant Rotations:**
   - If `k` equals the size of the array, after rotation the array will be the same as before
   - Calculate required rotation: `k = k % n` (where n = size of the array)
   - This handles cases where `k > n`

2. **Store Last K Elements:**
   - Since this is a right rotation, the last k elements need to be moved to the front
   - Store the last k elements in a vector named `store` serially
   - Example: for `nums = [1,2,3,4,5,6,7]` and `k = 3`, `store = [5,6,7]`

3. **Shift Remaining Elements:**
   - Take a pointer `l` which indicates the previous index of the last k elements
   - Set `l = n - k - 1` (last index before the k elements to be rotated)
   - Use a while loop active until `l` reaches the 0th index by decrementing
   - Inside the loop: move element from index `l` to index `l + k`
   - This shifts all elements from positions `[0, n-k-1]` to positions `[k, n-1]`

4. **Place Stored Elements:**
   - After the shifting loop, place elements from `store` vector serially to the beginning of the original array
   - Copy `store[i]` to `nums[i]` for i from 0 to k-1

### Step-by-Step Example:
For `nums = [1,2,3,4,5,6,7]`, `k = 3`:

1. **Initial:** `nums = [1,2,3,4,5,6,7]`, `k = 3`
2. **Store last k elements:** `store = [5,6,7]`
3. **Shift elements:** 
   - `l = 3`: `nums[6] = nums[3] = 4` → `nums = [1,2,3,4,5,6,4]`
   - `l = 2`: `nums[5] = nums[2] = 3` → `nums = [1,2,3,4,5,3,4]`
   - `l = 1`: `nums[4] = nums[1] = 2` → `nums = [1,2,3,4,2,3,4]`
   - `l = 0`: `nums[3] = nums[0] = 1` → `nums = [1,2,3,1,2,3,4]`
4. **Place stored elements:** `nums = [5,6,7,1,2,3,4]`

### Key Points:
- **Modulo Operation:** Use `k % n` to handle cases where k > array length
- **Right Rotation:** Last k elements move to the front, remaining elements shift right
- **In-place Modification:** Modify the original array (except for temporary storage)
- **Edge Cases:** Handle k = 0 (no rotation needed) and k >= n (use modulo)

### Visual Representation:
```
Original: [1,2,3,4,5,6,7]  k=3
          ↑-------↑ ^^^^^
          shift   store

After:    [5,6,7,1,2,3,4]
          ^^^^^  ↑-------↑
          stored shifted
```