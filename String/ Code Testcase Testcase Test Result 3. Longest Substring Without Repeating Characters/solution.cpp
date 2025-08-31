class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int longestLength = 0, l = 0, r = 0, cnt = 0;
        while (r < s.length()) {
            if (freq[s[r]] == 0) {
                freq[s[r]]++;
                r++;
            } else {
                while (1) {
                    if (s[l] == s[r]) {
                        freq[s[l]]--;
                        l++;
                        break;
                    } else {
                        freq[s[l]]--;
                        l++;
                    }
                }
            }
            longestLength = max(longestLength, r - l);
        }
        return longestLength;
    }
};