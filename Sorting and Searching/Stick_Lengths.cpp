// There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

// You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.

// What is the minimum total cost?

// Input

// The first input line contains an integer n: the number of sticks.

// Then there are n integers: p1,p2,…,pn: the lengths of the sticks.

// Output

// Print one integer: the minimum total cost.

// Constraints
// 1≤n≤2⋅105
// 1≤pi≤109
// Example

// Input:
// 5
// 2 3 1 5 2

// Output:
// 5

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
ll n,p[nxM];
 
 
int main(){
    cin >> n;
    ll ans = 0;
    for(int i=0; i<n; ++i){
        cin >> p[i];
    }
    sort(p, p+n);
    ll p_ = p[n/2];
    for(int i=0; i<n; ++i){
        ans += abs(p[i]-p_);
    }
    cout << ans;
}