class Solution {
public:
    int myAtoi(string s) {
        long long number = 0;
        bool flag = false;
        int neg = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                int digit = s[i] - 48;
                number = (number * 10) + digit;
                flag = true;
                if (number > 2147483648)
                    break;
            } else {
                if (flag)
                    break;
                else {
                    if (s[i] != ' ' && s[i] != '-' && s[i] != '+')
                        break;
                    else if (s[i] == '-') {
                        neg = -1;
                        flag = true;
                    } else if (s[i] == '+') {
                        flag = true;
                    }
                }
            }
        }
        number = number * neg;
        if (number < -2147483648)
            number = -2147483648;
        else if (number > 2147483647)
            number = 2147483647;
        return number;
    }
};