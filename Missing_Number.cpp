// You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.

// Input

// The first input line contains an integer n.

// The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).

// Output

// Print the missing number.

// Constraints
// 2≤n≤2⋅105
// Example

// Input:
// 5
// 2 3 1 5

// Output:
// 4

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h> 
#include <cstring>
 
#define ll long long
using namespace std;
 
const int nxM=2e5;
int n;
int x;
ll t,ans;
 
int main(){
    cin >> n;
    ans = 0;
    ll s = n;
    for(int i=1; i<n; ++i){
        cin >> x;
        ans += x;
        s+= i;
    }
    cout << s - ans;
}