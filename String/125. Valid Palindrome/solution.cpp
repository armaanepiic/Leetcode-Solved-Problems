class Solution {
public:
    bool checkPalindrome(int l, int r, string& s) {
        if (l >= r)
            return true;
        if(!isalnum(s[l])) {
            return checkPalindrome(l+1, r, s);
        }
        if(!isalnum(s[r])) {
            return checkPalindrome(l, r-1, s);
        }
        if (tolower(s[l]) != tolower(s[r]))
            return false;
        return checkPalindrome(l + 1, r-1, s);
    }
    bool isPalindrome(string s) { return checkPalindrome(0, s.length()-1, s); }
};