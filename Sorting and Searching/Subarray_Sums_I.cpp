// Given an array of n positive integers, your task is to count the number of subarrays having sum x.

// Input

// The first input line has two integers n and x: the size of the array and the target sum x.

// The next line has n integers a1,a2,…,an: the contents of the array.

// Output

// Print one integer: the required number of subarrays.

// Constraints
// 1≤n≤2⋅105
// 1≤x,ai≤109
// Example

// Input:
// 5 7
// 2 4 1 2 7

// Output:
// 3
#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n;
ll x, a[nxM];
 
int main(){
    cin >> n >> x;
    ll s=0;
    map<ll, int> mp; // frequency map of prefix sum
    mp[0]++;
    ll ans=0;
 
    for(int i=0; i<n; ++i){
        cin >> a[i];
        s += a[i];
        ans += mp[s-x];
        mp[s]++;
    }
 
    cout << ans;
 
}
