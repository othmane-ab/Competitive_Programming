// The Fibonacci numbers can be defined as follows:
// F0=0
// F1=1
// Fn=Fn−2+Fn−1
// Your task is to calculate the value of Fn for a given n.

// Input

// The only input line has an integer n.

// Output

// Print the value of Fn modulo 109+7.

// Constraints
// 0≤n≤1018
// Example

// Input:
// 10

// Output:
// 55

#include <bits/stdc++.h> 

#define ll long long
#define ar array 
using namespace std;

const int M=1e9+7;
ll n;
map<ll, ll> F;

ll f(ll _n) {
	if (F.count(_n)) return F[_n];
	ll k=_n/2;
	if (_n%2==0) { // _n=2*k
		return F[_n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // _n=2*k+1
		return F[_n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}


int main(){
    cin >> n, --n;
    F[0] = 0;
    F[1] = 1;
    cout << f(n);
}