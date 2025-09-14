# 268. Missing Number

**Problem Link:** [LeetCode 268 - Missing Number](https://leetcode.com/problems/missing-number/description/)  
**Category:** Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting

## Problem Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

## Examples

### Example 1
**Input:** nums = [3,0,1]  
**Output:** 2  
**Explanation:** `n = 3` since there are 3 numbers, so all numbers are in the range `[0,3]`. 2 is the missing number in the range since it does not appear in `nums`.

### Example 2
**Input:** nums = [0,1]  
**Output:** 2  
**Explanation:** `n = 2` since there are 2 numbers, so all numbers are in the range `[0,2]`. 2 is the missing number in the range since it does not appear in `nums`.

### Example 3
**Input:** nums = [9,6,4,2,3,5,7,0,1]  
**Output:** 8  
**Explanation:** `n = 9` since there are 9 numbers, so all numbers are in the range `[0,9]`. 8 is the missing number in the range since it does not appear in `nums`.

## Constraints

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

## Solution Approaches

### 1. Brute Force
**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

**Algorithm:**
- Loop from 0 to N (N = size of the vector)
- For each value, traverse the nums vector and search if the number appears or not
- If doesn't appear, flag remains false. Return that value.

### 2. Hash Table Approach (Better)
**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Algorithm:**
- Declare a hash vector of size = `nums.size() + 1`
- Traverse through the given vector and assign 1 to the relevant index of hash vector
- Finally traverse through the hash vector and search which index value is 0 and return that index

**Example:** For `nums = [3,0,1]`:
- Hash: `[0,0,0,0]` initially
- After marking: `[1,1,0,1]` (indices 0,1,3 marked)
- Missing number at index 2

### 3. Mathematical Sum Approach (Best)
**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Algorithm:**
- Take summation of numbers 0 to N: `S1 = 0+1+2+...+N = N*(N+1)/2` (where N = size of given vector)
- Traverse through the given vector and calculate the sum of each member: `S2`
- Return `S1 - S2`

**Example:** For `nums = [3,0,1]`:
- `S1 = 0+1+2+3 = 6`
- `S2 = 3+0+1 = 4`
- Missing = `6-4 = 2`

### 4. XOR Approach (Best - No Overflow Risk)
**Time Complexity:** O(n)  
**Space Complexity:** O(1)

**Algorithm:**
- Use XOR properties: `a^a = 0` and `0^a = a`
- `XOR1 = XOR of (0 to N)` where N = size of given vector
- `XOR2 = XOR of all members in given vector`
- Return `XOR1 ^ XOR2`

**Example:** For `nums = [3,0,1]`:
- `XOR1 = 0^1^2^3 = 0`
- `XOR2 = 3^0^1 = 2`
- Missing = `0^2 = 2`

**Why XOR works:**
- All numbers from 0 to N appear exactly once in the complete set
- All numbers in nums appear once, except the missing number appears zero times
- XORing complete set with nums cancels out all present numbers, leaving only the missing one

## Approach Comparison

| Approach | Time Complexity | Space Complexity | Pros | Cons |
|----------|----------------|------------------|------|------|
| Brute Force | O(n²) | O(1) | Simple to understand | Too slow for large inputs |
| Hash Table | O(n) | O(n) | Fast, easy to implement | Uses extra space |
| Math Sum | O(n) | O(1) | Optimal time & space | Risk of integer overflow |
| XOR | O(n) | O(1) | Optimal, no overflow risk | Requires understanding of bit manipulation |

## Key Insights

- **Range Property:** Array contains n numbers from range [0,n], so exactly one number is missing
- **Uniqueness:** All numbers are distinct, making mathematical approaches viable
- **XOR Advantage:** No risk of integer overflow compared to sum approach
- **Follow-up Solution:** Both Math Sum and XOR approaches satisfy O(1) space and O(n) time requirements