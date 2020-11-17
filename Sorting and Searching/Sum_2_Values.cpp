// Time limit: 1.00 s Memory limit: 512 MB
// You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

// Input

// The first input line has two integers n and x: the array size and the target sum.

// The second line has n integers a1,a2,…,an: the array values.

// Output

// Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

// Constraints
// 1≤n≤2⋅105
// 1≤x,ai≤109
// Example

// Input:
// 4 8
// 2 7 5 1

// Output:
// 2 4

#include <bits/stdc++.h>  
#define ll long long
#define ar array 
using namespace std;
 
const int mxN=2e5;
int n;
ll x;
map<int, int> mp;
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i){
        int t;
        cin >> t;
        auto it = mp.find(x-t);
        if(it!=mp.end()){
            cout << i+1 << " " << it->second+1;
            return 0;
        }else{
            mp[t] = i;
        }
    }
    cout << "IMPOSSIBLE";
 
}