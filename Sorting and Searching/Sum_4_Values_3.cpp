// You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

// Input

// The first input line has two integers n and x: the array size and the target sum.

// The second line has n integers a1,a2,…,an: the array values.

// Output

// Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

// Constraints
// 1≤n≤1000
// 1≤x,ai≤109
// Example

// Input:
// 8 15
// 3 2 5 8 1 3 2 3

// Output:
// 2 4 6 7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    map<int, ar<int,2>> mp;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            mp[a[i]+a[j]]={i, j};
        }
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int s=x-a[i]-a[j];
            if (s>0 && mp.count(s) && mp[s][0]>j) {
                cout << i+1 << " " << j+1 << " ";
                cout << mp[s][0]+1 << " " << mp[s][1]+1 << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}