// Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.

// Input

// The first input line has an integer n: the size of the array.

// The second line has n integers x1,x2,…,xn: the array values.

// Output

// Print n integers: for each array position the nearest position with a smaller value. If there is no such position, print 0.

// Constraints
// 1≤n≤2⋅105
// 1≤xi≤109
// Example

// Input:
// 8
// 2 5 1 4 8 3 2 5

// Output:
// 0 1 0 3 4 3 3 7

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n;
int a[nxM], n1[nxM];
 
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        n1[i] = i-1;
        while(~n1[i]&&a[n1[i]]>=a[i]){
            n1[i] = n1[n1[i]];
        }
        cout << n1[i]+1 << " ";
    }
 
 
}