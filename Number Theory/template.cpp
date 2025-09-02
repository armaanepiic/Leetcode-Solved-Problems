#include <bits/stdc++.h>
using namespace std;

void count_digits()
{
    int n, x, last_digit;
    cin >> n;
    x = n;
    int count = 0;
    vector<int> digits;
    // Method 1
    // TC : O(log10(n))
    while (x > 0)
    {
        last_digit = x % 10;
        digits.push_back(last_digit);
        count++;
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    cout << "Number of digits = " << count << endl;
    for (auto &it : digits)
        cout << it << ' ';
    cout << endl;
    // Method 2
    // TC : O(log10(n))
    int numberOfDigits = log10(n) + 1;
    cout << numberOfDigits;
}

void reverse_number()
{
    long long n, x, reverseNumber = 0;
    cin >> n;
    int neg = 1;
    if (n > -1)
    {
        x = n;
    }
    else
    {
        x = -1 * n;
        neg = -1;
    }
    while (x > 0)
    {
        int last_digit = x % 10;
        reverseNumber = (reverseNumber * 10) + last_digit;
        x /= 10;
    }
    cout << neg * reverseNumber;
}

bool isArmstrong(long long n)
{
    long long duplicate = n;
    int sum = 0, last_digit;
    int digits = log10(n) + 1;
    while (duplicate > 0)
    {
        last_digit = duplicate % 10;
        int temp = 1;
        for (int i = 0; i < digits; i++)
        {
            temp *= last_digit;
        }
        sum += temp;
        duplicate /= 10;
    }
    if (sum == n)
        return true;
    return false;
}

void divisors()
{
    vector<int> divisor;
    int n;
    cin >> n;
    // O(sqrt(n))
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            divisor.push_back(i);
        if ((n / i) != i)
            divisor.push_back(n / i);
    }
    sort(divisor.begin(), divisor.end()); // O(nlogn): n is the number of factors
    for (auto &it : divisor)
        cout << it << ' '; // O(n) : n is the number of factors

    // Total TC: O(sqrt(number)) + O(number of factors log(number of factors)) + O(number of factors)
}

void isPrime()
{
    // the number which has only two factors (1 and itself) is prime number.
    // N = 11; 11 has 2 factors -> 1, 11 so it is prime
    // N = 4; 4 has 3 factors -> 1, 2, 4. so it is not prime

    // Brute Force method, TC: O(N) ; N = number
    int cnt = 0, n;
    cin >> n;
    // for (int i = 1; i <= n; i++)
    //     if(n % i == 0) cnt++;
    // if(cnt > 2) cout << "NOT PRIME\n";
    // else cout << "PRIME\n";

    // Better method, TC: O(sqrt(n))
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (n / i != i)
                cnt++;
        }
    }
    if (cnt > 2) cout << "NOT PRIME\n";
    else cout << "PRIME\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // count_digits();
    // reverse_number();

    // long long n;
    // cin >> n;
    // cout << isArmstrong(n);

    // divisors();

    isPrime();

    return 0;
}