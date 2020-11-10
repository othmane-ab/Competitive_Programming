// Your task is to calculate the number of trailing zeros in the factorial n!.

// For example, 20!=2432902008176640000 and it has 4 trailing zeros.

// Input

// The only input line has an integer n.

// Output

// Print the number of trailing zeros in n!.

// Constraints
// 1≤n≤109
// Example

// Input:
// 20

// Output:
// 4

#include <iostream>
#include <cmath>
 
#define ll long long
 
using namespace std;
 
ll n;
 
int main(){
    cin >> n;
    ll m = (int)(log(n)/log(5));
    ll s = 0;
    for(int i=m; i>0; --i){
        s += (int)(n/pow(5,i));
    }
    cout << s;
}