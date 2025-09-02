# 7. Reverse Integer

**Problem Link:** [LeetCode 7 - Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)  
**Category:** Math, Medium

## Problem Description

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Note:** Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

## Examples

### Example 1
**Input:** x = 123  
**Output:** 321

### Example 2
**Input:** x = -123  
**Output:** -321

### Example 3
**Input:** x = 120  
**Output:** 21

## Constraints

- `-2^31 <= x <= 2^31 - 1`

## Solution Approach: Digit Extraction and Reversal

**Time Complexity:** O(log x) - where x is the input number (number of digits)  
**Space Complexity:** O(1) - only using constant extra space

### Algorithm Steps:

1. **Initialize variables:**
   - Declare two `long long int` values: `reverseNumber` and `n`
   - Initialize `x` to `n` to handle the case where reverse number might overflow the int data type

2. **Digit extraction and reversal:**
   - Run a loop until `n` reaches 0
   - In each iteration:
     - Extract the last digit: `remainder = n % 10`
     - Build reverse number: `reverseNumber = (reverseNumber * 10) + remainder`
     - Remove the last digit: `n = n / 10`

3. **Handle negative numbers:**
   - If the original `x` was negative, multiply `reverseNumber` by -1

4. **Overflow check:**
   - If `reverseNumber` is beyond the int data type range `[-2^31, 2^31 - 1]`, return 0
   - Otherwise, return the `reverseNumber`

### Key Points:
- Use `long long` to detect overflow without actually storing 64-bit results
- Handle negative numbers by preserving the sign separately
- The algorithm naturally handles trailing zeros (they become leading zeros and disappear)
- Check for 32-bit integer overflow before returning the result

### Edge Cases:
- Negative numbers: preserve the negative sign
- Numbers ending with zero: trailing zeros disappear in reversal (120 → 21)
- Overflow cases: return 0 when reversed number exceeds 32-bit range