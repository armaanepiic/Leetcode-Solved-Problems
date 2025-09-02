# 125. Valid Palindrome

**Problem Link:** [LeetCode 125 - Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/)  
**Category:** String, Two Pointer

## Problem Description

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

## Examples

### Example 1
**Input:** s = "A man, a plan, a canal: Panama"  
**Output:** true  
**Explanation:** "amanaplanacanalpanama" is a palindrome.

### Example 2
**Input:** s = "race a car"  
**Output:** false  
**Explanation:** "raceacar" is not a palindrome.

### Example 3
**Input:** s = " "  
**Output:** true  
**Explanation:** s is an empty string "" after removing non-alphanumeric characters.  
Since an empty string reads the same forward and backward, it is a palindrome.

## Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists only of printable ASCII characters.

## Solution Approach: Recursive Two Pointers

**Time Complexity:** O(n) - where n is the length of the string  
**Space Complexity:** O(n) - due to recursion stack depth

### Algorithm Steps:

1. **Base Case:**
   - If `left pointer >= right pointer`, that means all corresponding characters are equal
   - Return `true` (palindrome confirmed)

2. **Skip Non-Alphanumeric Characters:**
   - If left character is not alphanumeric: recursively call function with `(l+1, r, string)`
   - If right character is not alphanumeric: recursively call function with `(l, r-1, string)`

3. **Character Comparison:**
   - Convert both characters to lowercase and compare
   - If `lowercase(s[left]) != lowercase(s[right])`: return `false`
   - If they are equal: recursively call function with `(l+1, r-1, string)`

4. **Recursive Structure:**
   ```
   isPalindrome(s, left, right):
       if left >= right: return true
       if !isAlphanumeric(s[left]): return isPalindrome(s, left+1, right)
       if !isAlphanumeric(s[right]): return isPalindrome(s, left, right-1)
       if toLowerCase(s[left]) != toLowerCase(s[right]): return false
       return isPalindrome(s, left+1, right-1)
   ```

### Key Points:
- **Preprocessing:** Convert to lowercase and ignore non-alphanumeric characters on-the-fly
- **Two Pointers:** Start from both ends and move toward center
- **Recursion:** Each recursive call handles one step of the comparison process
- **Early Termination:** Return `false` as soon as a mismatch is found
- **Alphanumeric Check:** Only consider letters (a-z, A-Z) and digits (0-9)

### Edge Cases:
- Empty string or single character: always palindrome
- String with only non-alphanumeric characters: becomes empty, hence palindrome
- Mixed case letters: convert to lowercase for comparison
- Strings with spaces and punctuation: ignore them during comparison