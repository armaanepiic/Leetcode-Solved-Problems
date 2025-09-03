#include <bits/stdc++.h>
using namespace std;

void printSubsqnc(int ind, vector<int> &container, int arr[], int n) {
    if(ind == n) {
        for(auto &it : container) cout << it << ' ';
        cout << endl;
        return;
    }
    container.push_back(arr[ind]); // take
    printSubsqnc(ind+1, container, arr, n);
    container.pop_back(); // not take n  
    printSubsqnc(ind+1, container, arr, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    vector<int> container;
    printSubsqnc(0, container, arr, n);

    return 0;
}