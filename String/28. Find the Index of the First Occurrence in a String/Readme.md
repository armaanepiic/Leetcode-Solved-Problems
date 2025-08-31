# 28. Find the Index of the First Occurrence in a String

**Problem Link:** [LeetCode 28 - Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## Problem Description

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

## Examples

### Example 1
```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

### Example 2
```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

## Constraints

- `1 <= haystack.length, needle.length <= 10^4`
- `haystack` and `needle` consist of only lowercase English characters

## Solution Approaches

### 1. Brute Force

- `diff = length of haystack - length of needle`
- Traverse the haystack from index 0 to index `diff`
- Take a substring of the same length as needle and compare it with needle
- `substr(i, length of needle) == needle`
- Return value of `i` which is the starting index of substring similar to needle
- If not found, return -1
- **Time Complexity:** O(n*m) where n = haystack length, m = needle length
- **Space Complexity:** O(1)

### 2. Rolling Hash (Rabin-Karp Algorithm)

- Use polynomial hash function to compute hash values efficiently
- Create a prefix hash array to store cumulative hash values of haystack
- Create a power array to store powers of base for quick range hash calculation
- Generate hash for the needle pattern
- For each possible starting position in haystack:
  - Calculate hash of substring using range query: `getRangeHash(i, i + needle_length - 1)`
  - Compare with needle hash
  - If hashes match, return the starting index `i`
- If no match found, return -1
- **Time Complexity:** O(n + m) average case, O(n*m) worst case (hash collisions)
- **Space Complexity:** O(n) for prefix hash and power arrays