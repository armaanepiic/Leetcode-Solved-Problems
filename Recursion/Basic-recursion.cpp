#include <bits/stdc++.h>
using namespace std;

void printName(int i, int n)
{
    if (i > n)
        return;
    cout << "Arman\n";
    printName(i + 1, n);
}

void printOneToN(int i, int n)
{
    if (i > 5)
        return;
    cout << i << ' ';
    printOneToN(i + 1, n);
}

void printNtoOne(int i, int n)
{
    if (i > n)
        return;
    printNtoOne(i + 1, n);
    cout << i << ' ';
}

void printOneToNBacktrack(int i, int n)
{
    if (i == 0)
        return;
    printOneToNBacktrack(i - 1, n);
    cout << i << ' ';
}

void printNToOneBacktrack(int i, int n)
{
    if(i > n) return;
    printNToOneBacktrack(i+1, n);
    cout << i << ' ';
}

int sum_of_first_N(int n)
{
    if(n == 0) return 0;
    return  n + sum_of_first_N(n-1);
}

long long fact(int n)
{
    if(n == 1) return 1;
    return n * fact(n-1);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 1. print name 5 times

    // printName(1, n);

    // 2. print linearly from 1 to N

    // printOneToN(1, n);

    // 3. print from N to 1

    // printNtoOne(1, n);

    // 4. print linearly from 1 to N (By Backtracking)

    // printOneToNBacktrack(n, n);

    // 5. print N to 1 (By Backtraching)

    // printNToOneBacktrack(1, n);

    // print the sum from 1 to N
    // cout << "Sum of " << 1 << " to " << n << " = " << sum_of_first_N(n);

    // factorial of N
    cout << "Factorial of " << n << " = " << fact(n);
    
    return 0;
}
// 1. print name 5 times
// 2. print linearly from 1 to N
// 3. print from N to 1
// 4. print linearly from 1 to N (By Backtracking)
// 5. print N to 1 (By Backtraching)