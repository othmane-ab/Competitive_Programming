// Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

// Input

// The first input line has an integer n: the size of the array.

// The second line has n integers x1,x2,…,xn: the array values.

// Output

// Print one integer: the maximum subarray sum.

// Constraints
// 1≤n≤2⋅105
// −109≤xi≤109
// Example

// Input:
// 8
// -1 3 -2 5 3 -5 2 2

// Output:
// 9

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
ll n,x;
 
 
int main(){
    cin >> n;
    ll ans = -1e10, msf =-1e10;
    for(int i=0; i<n; ++i){
        cin >> x;
        msf = max(x, msf+x);
        ans = max(ans, msf);
    }
    cout << ans;
}