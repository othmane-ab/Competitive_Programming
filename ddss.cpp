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

// let f(n) be the (n + 1)th fibonacci number, we have two case: n is even and n is odd.

// f(2 * k) = f(k) * f(k) + f(k - 1) * f(k - 1)
// f(2 * k + 1) = f(k) * f(k + 1) + f(k - 1) * f(k)
// There are only at most O(4 log(n)) states. I don't like to prove this, but I can ensure it is true by doing some following experiment. 
// Let's divide n into groups by depth, you will realize a special property: Each depths only contains at most 4 values of n.



#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const long M = 1000000007; // modulo

map<long, long> F;
vector<long> T[1234];

long f(long n, int Depth) {
	T[Depth].push_back(n);
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k, Depth+1)*f(k, Depth+1) + f(k-1, Depth+1)*f(k-1, Depth+1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k, Depth+1)*f(k+1, Depth+1) + f(k-1, Depth+1)*f(k, Depth+1)) % M;
	}
}

main(){
	long n;
	F[0]=F[1]=1;
	if (cin >> n) {
		if (n==0) 
			cout << 0 << endl;
		else 
			cout << f(n-1, 0) << endl;
	}
	for (int i=0; i<1234; i++) if (T[i].size()) {
		sort(T[i].begin(), T[i].end());
		T[i].erase(unique(T[i].begin(), T[i].end()), T[i].end());
		printf("Depth[%d] : ", i);
		for (int j=0; j<T[i].size(); j++) printf("%lld ", T[i][j]);
		printf("\n");
	}
}