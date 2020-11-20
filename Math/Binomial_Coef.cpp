// Your task is to calculate n binomial coefficients modulo 109+7.

// A binomial coefficient (ab) can be calculated using the formula a!b!(a−b)!. We assume that a and b are integers and 0≤b≤a.

// Input

// The first input line contains an integer n: the number of calculations.

// After this, there are n lines, each of which contains two integers a and b.

// Output

// Print each binomial coefficient modulo 109+7.

// Constraints
// 1≤n≤105
// 0≤b≤a≤106
// Example

// Input:
// 3
// 5 3
// 8 1
// 9 5

// Output:
// 10
// 8
// 126
// The problem is the following: we want to compute the modular inverse for every number in the range [1,m−1].
// Here we present a better algorithm with complexity O(m). However for this specific algorithm we require that the modulus m is prime.
// We denote by inv[i] the modular inverse of i. Then for i>1 the following equation is valid:
// inv[i]=−⌊mi⌋⋅inv[mmodi]modm
#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;
 
const int mxA=1e5, mxX=1e9, M=1e9+7;
ll n;
ll iv[mxA], f1[mxA+1], f2[mxA+1];
 
int main(){
    cin.sync_with_stdio(0); 
    iv[1]=1;
    for(int i=2;i<=mxA;++i){
        iv[i] = M - M/i*iv[M%i]%M;
    }
    f1[0]=f2[0]=1;
    for(int i=1;i<=mxA;++i){
        f1[i] = f1[i-1]*i%M;
        f2[i] = f2[i-1]*iv[i]%M;
    }
    
    cin >> n;    
    ll ans;
    ll a,b;
    for(ll i=0; i<n; ++i){
        cin >> a >> b;
        ans = ((f1[a]*f2[b])%M*f2[a-b])%M ;
        cout << ans << "\n";
    }
}