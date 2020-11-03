#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=2e5;
int n,k;
ll a[mxN];
ll sum_cost[mxN];
// k = f(sum_cost)
// if sum_cost decreases then k decreases decreases or stays the same
int main(){
    cin >> n >> k;
    ll mx = 0;
    ll mn = 1e9;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(a[i]>mx) mx=a[i];
        if(a[i]<mn) mn=a[i];
    }
    ll lb=0,rb=(mx-mn)*1e9;
    while(lb<rb){
        ll mb = (lb+rb)/2;
        // compare size of sliding window with sum_cost = mb with k
        int c=0;
        ll ls=0;
        for(int i=0; i<n; ++i){
            if(ls+a[i]>mb){
                ++c;
                ls = 0;
            }
            ls += a[i];
        }
        ++c;
        if(c>k){
            lb = mb + 1;
        }else{
            rb = mb;
        }
    }
    cout << lb;

}