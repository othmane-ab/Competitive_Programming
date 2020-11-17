// Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.

// Input

// The first input line has an integer n: the size of the array.

// The next line has n integers a1,a2,…,an: the contents of the array.

// Output

// Print one integer: the required number of subarrays.

// Constraints
// 1≤n≤2⋅105
// −109≤ai≤109
// Example

// Input:
// 5
// 3 1 2 7 4

// Output:
// 1

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n;
ll a[nxM];
 
int main(){
    cin >> n;
    ll s=0;
    map<ll, int> mp; // frequency map of prefix sum
    mp[0]++;
    ll ans=0;
 
    for(int i=0; i<n; ++i){
        cin >> a[i];
        s = (s+a[i]%n+n)%n;
        ans += mp[s];
        mp[s]++;
    }
 
    cout << ans;
 
}
