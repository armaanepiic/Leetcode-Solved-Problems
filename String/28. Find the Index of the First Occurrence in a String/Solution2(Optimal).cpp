class Solution {
public:
    vector<long long> prefixHashStack, po;
    int base = 29;
    int MOD = 1000000007;

    void pre_process(string &haystack){
        prefixHashStack[0] = haystack[0];
        for(int i = 1 ; i < haystack.size() ; i++){
            prefixHashStack[i] = (prefixHashStack[i-1] * base) % MOD;
            prefixHashStack[i] += haystack[i];
            po[i] = ( po[i-1] * base ) % MOD;
        }
    }
    long long getRangeHash(int l, int r){
        long long x1 = prefixHashStack[r];
        long long x2 = l == 0 ? 0 : (prefixHashStack[l-1] * po[r - l + 1]) % MOD;
        return (x1 - x2 + MOD) % MOD;
    }
    long long generateHase(string &str){
        long long h = 0;
        for(auto s : str){
            h = (h * base) + s;
            h %= MOD;
        }
        return h;
    }
    int strStr(string haystack, string needle) {
        int la = haystack.size(), lb = needle.size();
        int range = la - lb;
        prefixHashStack.resize(la + 1 , 0);
        po.resize(la+1, 1);
        pre_process(haystack);
        long long nH = generateHase(needle);
        for(int i = 0; i <= range; i++){
            if(getRangeHash(i, i+lb-1) == nH)
                return i;
        }
        return -1;
    }
};