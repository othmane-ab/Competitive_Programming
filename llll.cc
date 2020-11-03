#include <bits/stdc++.h> 
#define ll long long
#define ar array 
using namespace std;

const int mxN=2e5;
int n,m;
ar <int,2> h[mxN];
int r[mxN];

int bs(int v, int a, int b){
    int l = a-1;
    int r = b;
    int m;
    while(r-l > 1){
        m = (int)(l+r)/2;
        if(h[m][0]<v){
            l = m;
        }else{
            r = m;
        }
    }
    return r;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> h[i][0], h[i][1]=i;
    }
    for(int i=0; i<m; ++i){
        cin >> r[i];
        sort(h,h+n);
        int e = bs(r[i], 0, n);
        if(h[e][0]>=r[i]){
            h[e][0] -= r[i];
            cout << h[e][1] + 1 << " ";
        }else{
            cout << "0 ";
        }
    }
}

// hotel queries
// sort the hotels by available rooms
// for each group 
    // do a binary search to find the first hotel able to accomodate // log n
    // decrease the hotel's availability and re-sort // log n