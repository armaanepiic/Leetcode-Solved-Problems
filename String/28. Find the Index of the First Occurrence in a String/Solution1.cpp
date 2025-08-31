class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_hay = haystack.length(), len_ned = needle.length();
        int range = len_hay - len_ned;
        for(int i = 0; i <= range; i++){
            if(haystack.substr(i, len_ned) == needle)
                return i;
        }
        return -1;
    }
};