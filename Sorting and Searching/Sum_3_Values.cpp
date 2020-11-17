// You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.

// Input

// The first input line has two integers n and x: the array size and the target sum.

// The second line has n integers a1,a2,…,an: the array values.

// Output

// Print three integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

// Constraints
// 1≤n≤5000
// 1≤x,ai≤109
// Example

// Input:
// 4 8
// 2 7 5 1

// Output:
// 1 3 4

#include <iostream>
#include <algorithm>
#include <array>
 
using namespace std;
 
#define ll long long
 
 
const int nxM = 5e3;
int n;
ll x;
array<int,2> a[nxM];
 
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i){
        cin >> a[i][0], a[i][1]=i;
    }
 
    sort(a, a+n);
    
    for(int i=0; i<n; ++i){
        ll x2 = x - a[i][0];
        for(int j=i+1,k=n-1; j<k; ++j){
            while(j<k&&a[j][0]+a[k][0]>x2){
                --k;
            }
            if(j<k&&a[j][0]+a[k][0]==x2){
                cout << a[i][1]+1 << " " << a[j][1]+1 << " " << a[k][1]+1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
