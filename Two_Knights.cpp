// Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.

// Input

// The only input line contains an integer n.

// Output

// Print n integers: the results.

// Constraints
// 1≤n≤10000
// Example

// Input:
// 8

// Output:
// 0
// 6
// 28
// 96
// 252
// 550
// 1056
// 1848

#include <iostream>
 
#define ll long long
 
using namespace std;
 
ll n;
 
int main(){
    cin >> n;
    for(ll k=1; k<n+1; ++k){
        if(k==1){
            cout << 0 << "\n";
        }else if(k==2){
            cout << 6 << "\n";
        }else if(k==3){
            cout << 28 << "\n";
        }else{
            ll r = k-3+1;
            ll s = 8 + 6*(r-1);
            for(ll i=1; i<r; ++i){
                s += 6 + 4*(r-1);
            }
            cout << k*k*(k*k-1)/2 - s << "\n";
        }
    }
}
