// You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

// Input

// The first input line has two integers n and x: the array size and the target sum.

// The second line has n integers a1,a2,…,an: the array values.

// Output

// Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

// Constraints
// 1≤n≤1000
// 1≤x,ai≤109
// Example

// Input:
// 8 15
// 3 2 5 8 1 3 2 3

// Output:
// 2 4 6 7

// First, we create two sorted vectors A,B with pairs. 
// Second, we know there is a solution with the indices in sorted order, 
// thus we only create pairs a,b with a<b. 
// to solve ties in A we try to minimize b 
// and to solve ties in B we maximize a. 
// Now while doing the meet in the middle 
// we only combine entries from (a,b)∈A with entries (c,d)∈B where b<c.

#include <bits/stdc++.h> 
 
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN = 1e3;
int n;
ll x;
vector<ar<int, 2>> A,B;
int a[mxN];

bool sortbysec(const ar<int,2> &_a, 
              const ar<int,2> &_b) 
{ 
    if((_a[0] < _b[0])) return true;
    else if((_a[0] == _b[0]) && (_a[1] < _b[1])){
        return true;
    }
} 

int main(){
    cin >> n >> x;

    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(a[i]<a[j]){
                A.push_back({i, j});
                B.push_back({i, j});// i<j
            }
        }
    }

    sort(A.begin(), A.end());




    int y=0;
    cout << "IMPOSSIBLE";
}
