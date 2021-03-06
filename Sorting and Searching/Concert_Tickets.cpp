// There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

// Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

// Input

// The first input line contains integers n and m: the number of tickets and the number of customers.

// The next line contains n integers h1,h2,…,hn: the price of each ticket.

// The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

// Output

// Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

// If a customer cannot get any ticket, print −1.

// Constraints
// 1≤n,m≤2⋅105
// 1≤hi,ti≤109
// Example

// Input:
// 5 3
// 5 3 7 8 5
// 4 8 3

// Output:
// 3
// 8
// -1

#include <bits/stdc++.h> 
 
#define ll long long
#define ar array 
using namespace std;
 
const int nxM=2e5;
int n,m;
// const int nxM=12;
int ans;
 
int main(){
    cin >> n >> m;
    set<ar<int,2>> s;
    int h;
    for(int i=0;i<n;++i){
        cin >> h;
        s.insert({h, i});
    }
    for(int i=0;i<m;++i){
        int t;
        cin >> t;
        auto it = s.lower_bound({t+1, 0});
        if(it==s.begin()){
            cout << "-1\n";
        }else{
            --it;
            cout << (*it)[0] << "\n";
            s.erase(it);
        }
    }
}
