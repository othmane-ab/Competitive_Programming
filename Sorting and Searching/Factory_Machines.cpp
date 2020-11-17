// Time limit: 1.00 s Memory limit: 512 MB
// A factory has n machines which can be used to make products. Your goal is to make a total of t products.

// For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.

// What is the shortest time needed to make t products?

// Input

// The first input line has two integers n and t: the number of machines and products.

// The next line has n integers k1,k2,…,kn: the time needed to make a product using each machine.

// Output

// Print one integer: the minimum time needed to make t products.

// Constraints
// 1≤n≤2⋅105
// 1≤t≤109
// 1≤ki≤109
// Example

// Input:
// 3 7
// 3 2 5

// Output:
// 8

// Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n,t,a[nxM];
 
 
int main(){
    cin >> n >> t;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    ll lb=1, rb=1e18;
    while(lb<rb){// we want min 2x+2y+5z with x+y+z>=t
        ll mb=(lb+rb)/2, s=0;
        for(int i=0; i<n; ++i){
            s+=min(mb/a[i], (ll)1e9);
        }// s is nbr of products created
        if(s>=t){
            rb = mb;
        }else{
            lb = mb+1;
        }
    }
    cout << lb;
}
