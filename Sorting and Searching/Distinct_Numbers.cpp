// You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

// Input

// The first input line has an integer n: the number of values.

// The second line has n integers x1,x2,…,xn.

// Output

// Print one integers: the number of distinct values.

// Constraints
// 1≤n≤2⋅105
// 1≤xi≤109
// Example

// Input:
// 5
// 2 3 2 2 3

// Output:
// 2

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
int n;
int main(){
    cin >> n;
    set<int> s;
    for(int i=0; i<n; ++i){
        ll t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size();
}
