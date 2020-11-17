// In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

// Input

// The first input line has an integer n: the number of movies.

// After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

// Output

// Print one integer: the maximum number of movies.

// Constraints
// 1≤n≤2⋅105
// 1≤a<b≤109
// Example

// Input:
// 3
// 3 5
// 4 9
// 5 8

// Output:
// 2

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n;
ar<int, 2> a[nxM];
 
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i][1] >> a[i][0];
    }
    sort(a, a+n);
    int ans=0, l=0;
    for(int i=0; i<n; ++i){
        if(a[i][1]>=l){
            ++ans;
            l = a[i][0];
        }
    }
    cout << ans;
 
}
