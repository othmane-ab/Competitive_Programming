// You are given the arrival and leaving times of n customers in a restaurant.

// What was the maximum number of customers?

// Input

// The first input line has an integer n: the number of customers.

// After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

// You may assume that all arrival and leaving times are distinct.

// Output

// Print one integer: the maximum number of customers.

// Constraints
// 1≤n≤2⋅105
// 1≤a<b≤109
// Example

// Input:
// 3
// 5 8
// 2 4
// 3 9

// Output:
// 2

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n,a,b;
// const int nxM=12;
int ans;
 
int main(){
    cin >> n;
    set<ar<int,2>> s;
    for(int i=0;i<n;++i){
        cin >> a >> b;
        s.insert({a, 1});
        s.insert({b+1, -1});
    }
    int c=0;
    for(ar<int,2> e:s){
        c += e[1];
        ans = max(c, ans);
    }
    cout << ans;
}
// 5 8 1
// 2 4 1
//  => 3 9 
 
// 2 2 1
// 3 4 2
// 5 8 2
// 9 9 1