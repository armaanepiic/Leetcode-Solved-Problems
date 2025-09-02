class Solution {
public:
    int reverse(int x) {
        long long reverseNumber = 0, n;
        n = x;
        int neg = 1,last_digit;
        if(n < 0){
            neg = -1;
            n *= -1;
        } 
        while (n > 0) {
            last_digit = n % 10;
            reverseNumber = (reverseNumber * 10) + last_digit;
            n /= 10;
        }
        if(reverseNumber > 2147483647 || reverseNumber < -2147483648)
            return 0;
        return neg * reverseNumber;
    }
};
// 2147483648