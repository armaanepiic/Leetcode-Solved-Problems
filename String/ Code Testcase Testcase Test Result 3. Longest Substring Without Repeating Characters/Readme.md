# 3. Longest Substring Without Repeating Characters

**Problem Link:** [LeetCode 3 - Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

## Problem Description

Given a string `s`, find the length of the **longest** **substring** without duplicate characters.

## Examples

### Example 1
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

### Example 2
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

### Example 3
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

## Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

## Solution Approach: Sliding Window (Two Pointers)

- Use two pointers `l` (left) and `r` (right), both starting at index 0
- Create a frequency vector `freq` of size 256 (for ASCII characters) initialized with 0
- Increment the right pointer `r` to expand the window
- Store character count in the `freq` vector
- When finding an element whose value is already 1 in the `freq` vector (duplicate character):
  - Shift the left pointer `l` to just next to the previous duplicated character
  - Decrement the count of each element as the left pointer moves
- Update the maximum count as `longestLength = max(longestLength, r - l + 1)`
- Continue until the right pointer reaches the end of string
- **Time Complexity:** O(n) where n = string length
- **Space Complexity:** O(1) - fixed size array of 256