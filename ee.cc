#include <bits/stdc++.h> 

#define ll long long
#define ar array 
using namespace std;

const int nxM=2e5;
int n,x,a[nxM];
// const int nxM=12;

int main(){
    cin >> n >> x;
    for(int i =0; i<n; ++i){
        cin >> a[i];
    }
    int found = 0;
    sort(x, x+n);
    for(int i=0; i<n; ++i){
        int j = i+1;
        while(a[j]<x-a[i]&&j<n){
            ++j;
        }
        if(a[j]+a[i]==x){
            found = 1;
            cout << i << j;
        }
    }
    if(!found){
        cout << "IMPOSSIBLE";
    }
}