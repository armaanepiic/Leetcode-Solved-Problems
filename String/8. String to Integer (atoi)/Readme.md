# 8. String to Integer (atoi)

**Problem Link:** [LeetCode 8 - String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/description/)

## Problem Description

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer.

The algorithm for `myAtoi(string s)` is as follows:
1. **Whitespace**: Ignore any leading whitespace (`" "`).
2. **Signedness**: Determine the sign by checking if the next character is `'-'` or `'+'`, assuming positivity if neither present.
3. **Conversion**: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. **Rounding**: If the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, then round the integer to remain in the range. Specifically, integers less than `-2^31` should be rounded to `-2^31`, and integers greater than `2^31 - 1` should be rounded to `2^31 - 1`.

Return the integer as the final result.

## Examples

### Example 1
**Input:** s = "42"  
**Output:** 42  
**Explanation:**
```
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
```

### Example 2
**Input:** s = " -042"  
**Output:** -42  
**Explanation:**
```
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
```

### Example 3
**Input:** s = "1337c0d3"  
**Output:** 1337  
**Explanation:**
```
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
```

### Example 4
**Input:** s = "0-1"  
**Output:** 0  
**Explanation:**
```
Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
```

### Example 5
**Input:** s = "words and 987"  
**Output:** 0  
**Explanation:** Reading stops at the first non-digit character 'w'.

## Constraints

- `0 <= s.length <= 200`
- `s` consists of English letters (lower-case and upper-case), digits (`0-9`), `' '`, `'+'`, `'-'`, and `'.'`.

## Solution Approach: State Machine

**Time Complexity:** O(n) where n = string length

### Algorithm Steps:
- Traverse the whole string character by character
- Use a `flag` to indicate whether number building has started
- Use `neg` to track the sign of the number (1 for positive, -1 for negative)

### Character Processing Logic:
1. **If current character is a digit (0-9):**
   - Start building the number: `number = (number * 10) + digit`
   - Set `flag = true` to indicate number building has started
   - Check for overflow: if `number > 2^31`, break the loop

2. **If current character is not a digit:**
   - **If `flag` is true** (number building has started): break the loop
   - **If `flag` is false** (number building hasn't started yet):
     - **Space character (' '):** ignore and continue
     - **Minus sign ('-'):** set `neg = -1` and `flag = true`
     - **Plus sign ('+'):** set `flag = true` (keep positive)
     - **Any other character:** break the loop

3. **Final Range Checking:**
   - Apply the sign: `number = number * neg`
   - If `number < -2^31`: clamp to `-2^31`
   - If `number > 2^31 - 1`: clamp to `2^31 - 1`

### Key Points:
- Once we encounter a sign (`+` or `-`) or start reading digits, we can't accept more signs
- Leading whitespaces are ignored only before any meaningful character
- The algorithm stops at the first non-digit character after number building starts
- Handle 32-bit integer overflow by clamping to the valid range `[-2^31, 2^31-1]`

**Space Complexity:** O(1) - only using a few variables